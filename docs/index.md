# scftolus - Luscus extension

Scftolus is a Luscus extension granting support for using scf as
input for generating Luscus scenes.

# Building C++ code

## Working directory

In OS shell, navigate to scftolus repository folder you have cloned from [https://github.com/Argmaster/scftolus](https://github.com/Argmaster/scftolus).

```
git clone https://github.com/Argmaster/scftolus.git
```

## Installing dependencies

!!! Warning

    **Required**: [Python 3.x](https://www.python.org/downloads/) interpreter, at least version 3.9

All project dependencies are included as git submodules.

!!! Warning

    Watch out to use appropriate for your platform python interpreter alias.
    On Unix-like platforms python 3.x is commonly aliased as `python3`, on Windows
    you might have installed python loader which can be invoked with `py -3.9`.

To install dependencies use

```
python3 scripts/install_libs.py
```

## Compilation

!!! Warning

    **Required**: [CMAKE](https://cmake.org/download/) version 3.19 or newer.

Create directory to store build files:

```
mkdir build
```

Generate build system configuration files:

```
cmake ..
```

!!! Info

    During development of this code, Ninja build system is used,
    but feel free to use your favorite, however in this example
    we will use ninja.

Build binary files:

```
ninja
```

# Documentation

To build yourself documentation, you need Python 3 interpreter,
at least version 3.9.

!!! Warning

    Watch out to use appropriate for your platform python interpreter alias.
    On Unix-like platforms python 3.x is commonly aliased as `python3`, on Windows
    you might have installed python loader which can be invoked with `py -3.9`.

!!! Info

    Preferred way to install dependencies is to create virtual environment to store them.
    It can be done with:
    ```
    python3 -m venv .env
    ```
    Then virtual environment have to be enabled via:

    - On Unix-like:
        ```
        source .env/bin/activate
        ```

    - On Windows:

        - Powershell:
            ```
            .env\Scripts\activate.bat
            ```
        - cmd.exe:
            ```
            .env\Scripts\Activate.ps1
            ```

    [See Python's venv documentation.](https://docs.python.org/3/library/venv.html)

After, run following command to install doc
builder and dependencies:

```
python -m pip install -r requirements-docs.txt
```

To live view docs use

```
mkdocs serve
```

To build docs web page use

```
mkdocs build
```

Static site can be viewed by opening `./site/index.html` in web browser
