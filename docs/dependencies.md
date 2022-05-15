# scftolus dependencies

To ensure reliability, scftolus avoids redesigning a wheel, and
uses open source libraries for handling **everything** that doesn't
have to be written ground up. This approach guarantees that
utilities used are maintained and well tested, despite limited
time, scftolus developers have to work on this project.

## Command line interface - [CLI11](https://github.com/CLIUtils/CLI11)

CLI11 is a command line parser for C++11 and beyond that provides a rich feature set with a simple and intuitive interface.

Currently used version: v2.2.0

-   [Visit this repository at GitHub](https://github.com/CLIUtils/CLI11)
-   [CLI11 documentation](https://cliutils.github.io/CLI11/book/)

## XML parsing - [pugixml](https://github.com/zeux/pugixml)

pugixml is a C++ XML processing library, which consists of a DOM-like interface with rich traversal/modification capabilities, an extremely fast XML parser which constructs the DOM tree from an XML file/buffer, and an XPath 1.0 implementation for complex data-driven tree queries. Full Unicode support is also available, with Unicode interface variants and conversions between different Unicode encodings (which happen automatically during parsing/saving).

pugixml is used by a lot of projects, both open-source and proprietary, for performance and easy-to-use interface.

Currently used version: v1.12.1

-   [Visit this repository at GitHub](https://github.com/zeux/pugixml)
-   [Quick-start guide](https://pugixml.org/docs/quickstart.html)
-   [Complete reference manual](https://pugixml.org/docs/quickstart.html)

## Logging - [spdlog](https://github.com/gabime/spdlog)

Very fast, header-only/compiled, C++ logging library.

Currently used version: v1.10.0

-   [Visit this repository at GitHub](https://github.com/gabime/spdlog)
-   [spdlog wiki](https://github.com/gabime/spdlog/wiki)

## String formatting - [fmt](https://github.com/fmtlib/fmt)

{fmt} is an open-source formatting library providing a fast and safe alternative to C stdio and C++ iostreams.

If you like this project, please consider donating to one of the funds that help victims of the war in Ukraine: https://www.stopputin.net/.

Currently used version: 8.1.1

-   [Visit this repository at GitHub](https://github.com/fmtlib/fmt)
-   [Documentation](https://fmt.dev/)
-   [Cheat Sheets](https://hackingcpp.com/cpp/libs/fmt.html)

## Unit testing - [GoogleTest](https://github.com/google/googletest)

This repository is a merger of the formerly separate GoogleTest and GoogleMock projects. These were so closely related that it makes sense to maintain and release them together.

-   [Visit this repository at GitHub](https://github.com/google/googletest)
-   [Documentation](https://google.github.io/googletest/)
-   [GoogleTest Primer](https://google.github.io/googletest/primer.html)
