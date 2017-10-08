[![Licence](https://img.shields.io/github/license/JaroslawWiosna/regionalizer.svg)]()
[![Release](https://img.shields.io/github/release/JaroslawWiosna/regionalizer.svg?maxAge=3600)](https://github.com/JaroslawWiosna/regionalizer/releases)
[![GitHub contributors](https://img.shields.io/github/contributors/JaroslawWiosna/regionalizer.svg)](https://github.com/JaroslawWiosna/regionalizer/graphs/contributors)
[![Travis status](https://travis-ci.org/JaroslawWiosna/regionalizer.svg)](https://travis-ci.org/JaroslawWiosna/regionalizer)
[![Coverage Status](https://coveralls.io/repos/github/JaroslawWiosna/regionalizer/badge.svg)](https://coveralls.io/github/JaroslawWiosna/regionalizer)
# regionalizier

> TBD

  - [Overview](#overview)
  - [How to clone?](#how-to-clone)
  - [How to generate doxygen documentation?](#how-to-generate-doxygen-documentation)
  - [Creating database using city_update_tool](#creating-database-using-city_update_tools)
  - [Algorithms](#algorithms)
  - [Coding style](#coding-style)
  - [Special thanks to](#special-thanks-to)

---

## Overview

[![image](https://i.imgur.com/UqwvidQ.png)](https://i.imgur.com/UqwvidQ.png)

---

## How to clone?

This repository has a submodule inside. In order to clone the repo with submodule use
```sh
git clone --recursive https://github.com/JaroslawWiosna/regionalizer.git
cd regionalizer
```
...or if you have already cloned the repo without `recursive` flag:
```sh
git clone https://github.com/JaroslawWiosna/regionalizer.git
cd regionalizer
git submodule update --init --recursive
```

[Thanks to mklement0](https://stackoverflow.com/questions/3796927/how-to-git-clone-including-submodules)

---

## How to generate doxygen documentation?

```sh
doxygen doxygenConfigurationFile
```
...then please find `index.html` in `html` directory.

---

## Creating database using city_update_tool

Run in java eclipse: file `city_update tool` to get text file `cities_data_pre_parsed` with cites name, area(km^2) and population
Now run in java eclipse: file `city_update tool2` to get full city database text file `cities_data` containg data from `cities_data_pre_parsed` with additional cities longitude and latitude.
Remember about the order of runing city_update_tool first. Otherwise you will get wrong results!!

---

## Algorithms

> TBD

---

## Coding style

### Naming convention

> Use CamelCase

### Spaces or tabs?

> Use spaces only. 4 spaces per indentiation level.

### Maximum line length

> Limit is 79 characters per line.

---

## Special thanks to
https://gronlier.fr/blog/2015/01/adding-code-coverage-to-your-c-project/

