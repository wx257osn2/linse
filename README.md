# Linse

Linse is a header-only readline library for C++17.

## Origin

Linse is a forked project of [arangodb/linenoise-ng](https://github.com/arangodb/linenoise-ng).
Linenoise Next Gneration is based on [antirez/linenoise](https://github.com/antirez/linenoise).

## Features

Linse is based on linenoise-ng, so it also has the features below:

* single-line and multi-line editing mode with the usual key bindings implemented
* history handling
* completion
* BSD license source code
* Only uses a subset of VT100 escapes (ANSI.SYS compatible)
* UTF8 aware
* support for Linux ~~, MacOS~~ and Windows
    * Linse may be worked on MacOS, but I don't check it because I have no Mac.

It is very important point that **Linse doesn't have linenoise-compatible pure-C interface**.
It means that you can't replace linenoise or linenoise-ng on your code to Linse without
changing code.

## Requirements

You need C++17-enabled compiler to use this library.

## Usage
see `example/example.cpp`

## License
3-clause BSD license ((C) I)
