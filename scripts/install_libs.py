from dataclasses import dataclass
import json
import logging
import os
from pathlib import Path
import subprocess as sbp
from typing import Optional

EXTERNAL_DEFINITIONS_FILE: Path = Path(".external")


@dataclass
class SubmoduleDef:
    path: Optional[str] = None
    tag: Optional[str] = None
    branch: Optional[str] = None


def install_libs() -> int:
    definitions = load_external_definitions()
    checkout_git_submodules()
    checkout_defined_versions(definitions)

    return 0


def checkout_defined_versions(definitions):
    submodules = definitions.get("submodules", [])
    for i, submodule in enumerate(submodules):
        if not isinstance(submodule, dict):
            logging.error(
                f"Invalid format of {i + 1}th submodule, it "
                f"should be dict, but {type(submodule)} found."
            )
            continue

        submodule = SubmoduleDef(**submodule)

        retval = ensure_version(submodule)
        if retval != 0:
            logging.error(
                f"Failed to ensure version of {i + 1}th submodule "
                f"({submodule.path}) with exit code {retval}."
            )
            continue


def load_external_definitions():
    if not EXTERNAL_DEFINITIONS_FILE.is_file():
        logging.error(
            "External definition file doesn't exist "
            f"({EXTERNAL_DEFINITIONS_FILE}), can't validate "
            "submodules versions."
        )
        exit(-1)
    else:
        logging.info(
            "External definitions file found at "
            f"{EXTERNAL_DEFINITIONS_FILE.absolute()}."
        )
    try:
        with EXTERNAL_DEFINITIONS_FILE.open("r", encoding="utf-8") as file:
            return json.load(file)
    except json.JSONDecodeError:
        logging.error(
            "Failed to external definitions file due to JSON syntax error.",
        )
        exit(-2)


def checkout_git_submodules():
    retval = sbp.run(["git", "submodule", "update", "--init", "--recursive"])
    if retval.returncode != 0:
        logging.error("Failed to checkout newest versions of git submodules.")
        exit(retval.returncode)
    else:
        logging.info("Checked out newest versions of git submodules.")


def ensure_version(submodule: SubmoduleDef):
    cwd = Path.cwd().resolve()

    if submodule.path is None:
        return -3

    os.chdir(submodule.path)

    if submodule.branch is not None:
        retval = sbp.run(["git", "checkout", submodule.branch])
        if retval.returncode != 0:
            logging.info(
                "Failed to checkout branch "
                f"'{submodule.branch}' for {submodule.path}"
            )
            return retval.returncode
        else:
            logging.info(
                "Checked out branch "
                f"'{submodule.branch}' for {submodule.path}"
            )

    if submodule.tag is not None:
        retval = sbp.run(["git", "checkout", submodule.tag])
        if retval.returncode != 0:
            logging.info(
                "Failed to checkout tag "
                f"'{submodule.tag}' for {submodule.path}"
            )
            return retval.returncode
        else:
            logging.info(
                "Checked out tag " f"'{submodule.tag}' for {submodule.path}"
            )

    os.chdir(cwd)

    return 0


if __name__ == "__main__":
    exit(install_libs())
