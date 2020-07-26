# PBR

An implementation of the book [Physically Based Rendering](http://www.pbr-book.org/).  

## Table of Contents

- [Library](#library)
- [Documentation](#documentation)
- [Building](#building)
- [Build Status](#build-status)

## Library

_Work in progress_

## Documentation

Doxygen documentation based on the latest state of master, [hosted by GitHub Pages](https://moddyz.github.io/PBR/).

## Building

A convenience build script is provided, for building all targets, and optionally installing to a location:
```
./build.sh <OPTIONAL_INSTALL_LOCATION>
```

### Requirements

- `>= CMake-3.17`
- `C++17`
- `doxygen` and `graphviz` (optional for documentation)

## Build Status

|       | master | 
| ----- | ------ | 
| macOS-10.14 | [![Build Status](https://travis-ci.com/moddyz/PBR.svg?branch=master)](https://travis-ci.com/moddyz/PBR) |
