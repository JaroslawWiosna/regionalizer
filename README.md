[![Licence](https://img.shields.io/github/license/JaroslawWiosna/regionalizer.svg)](https://github.com/JaroslawWiosna/regionalizer/blob/master/LICENSE)
[![Release](https://img.shields.io/github/release/JaroslawWiosna/regionalizer.svg?maxAge=3600)](https://github.com/JaroslawWiosna/regionalizer/releases)
[![GitHub contributors](https://img.shields.io/github/contributors/JaroslawWiosna/regionalizer.svg)](https://github.com/JaroslawWiosna/regionalizer/graphs/contributors)
[![Travis status](https://travis-ci.org/JaroslawWiosna/regionalizer.svg?branch=master)](https://travis-ci.org/JaroslawWiosna/regionalizer)
[![Coverage Status](https://coveralls.io/repos/github/JaroslawWiosna/regionalizer/badge.svg?branch=master)](https://coveralls.io/github/JaroslawWiosna/regionalizer?branch=master)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/48b007a2de3648df9f3ca61c77ad45af)](https://www.codacy.com/app/JaroslawWiosna/regionalizer?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=JaroslawWiosna/regionalizer&amp;utm_campaign=Badge_Grade)

# regionalizer [![Watchers](https://img.shields.io/github/watchers/JaroslawWiosna/regionalizer.svg?style=social&label=Watch)](https://github.com/JaroslawWiosna/regionalizer/watchers) [![Star](https://img.shields.io/github/stars/JaroslawWiosna/regionalizer.svg?style=social&label=Stars)](https://github.com/JaroslawWiosna/regionalizer/stargazers) [![Fork](https://img.shields.io/github/forks/JaroslawWiosna/regionalizer.svg?style=social&label=Fork)](https://github.com/JaroslawWiosna/regionalizer/network)

> **regionalizer** /ˈriːdʒ(ə)n(ə)lʌɪzə/ - the one who regionalizes.
>
> **to regionalize** [/ˈriːdʒ(ə)n(ə)lʌɪz/](https://en.oxforddictionaries.com/definition/regionalize) - to divide into regions, especially for administrative purposes. <sub> [based on thefreedictionary](https://www.thefreedictionary.com/regionalize) </sub>
>
> How to choose the best capital of a state and regions?

  - [Overview](#overview)
  - [How to build?](#how-to-build)
  - [How to contribute?](#how-to-contribute)
  - [How to generate doxygen documentation?](#how-to-generate-doxygen-documentation)
  - [Creating database using city_update_tool](#creating-database-using-city_update_tools)
  - [Algorithms](#algorithms)
  - [Clang format](#clang-format)
  - [Coding style](#coding-style)
  - [Special thanks to](#special-thanks-to)

---

## Overview

[![image](https://i.imgur.com/tTPunlN.png)](https://i.imgur.com/tTPunlN.png)
[![image](https://media.giphy.com/media/3o7aCR7bNwd8EqMuAM/giphy.gif)](https://media.giphy.com/media/3o7aCR7bNwd8EqMuAM/giphy.gif)
[![image](https://i.imgur.com/FCHbFmN.png)](https://i.imgur.com/FCHbFmN.png)
[![image](https://i.imgur.com/ZRhei6y.png)](https://i.imgur.com/ZRhei6y.png)

How could we know what is the best city to locate the headquaters of our company?
 - Should we locate it in the biggest city?
 - ..or in the centre of the state? (so the distance to the farthest city would be as small as possible?)
The first option is quite all right, but so boring.
I guess the primary objective is to make everyone **happy**
Let's think about happiness for a second.

> There is neither happiness nor misery in the world; there is only the comparison of one state with another, nothing more. 

This line from [The Count of Monte Cristo](https://en.wikisource.org/wiki/The_Count_of_Monte_Cristo/Chapter_117) ending gave us a clue about happiness.
Every City wants to be the capital. Only then the happiness would be **max**. The worst case for a specific city would occur when the capital is in the middle of nowhere.
Only then the happiness would be **min**. When the capital is somewhere in between, the happiness would be somewhere in between as well.

Here is an example:

- Hey, [Szczecin](https://en.wikipedia.org/wiki/Szczecin) tell me where the capital of Poland should be.
 - *Near Szczecin, of course!*
 - Yeah..., but the capital should be in the center of the state, don't you think?
 - *well..., I agree, but I do not want the capital to be [Rzeszow](https://en.wikipedia.org/wiki/Rzesz%C3%B3w) It would be too far!*

---

When we have `a capital canditate`, let's find out what other cities think about it.
 - Each city has an information about `the farthest` city.
 - Let's calculate the distance between `a capital canditate` and A <-- first city of the vector(a.k.a. state, a.k.a. country)
 - calculate `HI` which is `Happiness Index` = 10 * (calculated distance between A and `the candidate` / distance to the farthest city)
 - calculate `HL` which is `Happiness Level` = `HI * population of A`
 - Do it with every single city in the vector and the sum of `HL` of every single city is **the value**. It is like **votes**. Candidate with the greatest value of `HL` would be elected as the new capital.

---

~~With that being said the algorithm is quite obvious:~~
 - ~~Assign the distance of the farthest city from every single one of city.~~
 - ~~Check what would be the happiness level of the whole population when the capital is "the specific" city.~~
 - ~~Check every possible city~~~~

~~The objectives of the project~~
 - [x] ~~Choose the best city for capital (or for the location of headquaters)~~
 - [ ] ~~Choose the best cities for capitals of the regions. (Numer of regions will be passed as argvs)~~
 - [ ] ~~Chosse the optimal number of regions. (Every city wants to be the capital, but there is no sense...)~~

---

## How to build?

```sh
mkdir build
cd build
cmake ..
make
make test
./regionalizer --list ../database/cities_data
```

---

## How to contribute?
Please, have a look [here](https://www.github.com/JaroslawWiosna/regionalizer/blob/master/CONTRIBUTING.md)

---

## How to generate doxygen documentation?

```sh
doxygen doxygenConfigurationFile
```
...then please find `index.html` in `html` directory.

---

## Creating database using city_update_tool

Run in java eclipse: file `city_update tool` to get text file `cities_data_pre_parsed` with cites name, area(km^2) and population<br />
Now run in java eclipse: file `city_update tool2` to get full city database text file `cities_data` containg data from `cities_data_pre_parsed` with additional cities longitude and latitude and remove polish letters from city's names. There are no cardinal directions like "E". The coordinates minutes are in form of decimal part of the degrees with a precision set to 4 digits after the comma.<br />
Remember about the order of runing city_update_tool first. Otherwise you will get wrong results!!<br />
Database final order is as following: City name|Area|Population|Latitude|Longitude

---

## Algorithms

> TBD

---

## Clang format

As it is important for us to keep common rules of clean code for the repository we introduce the clang-format. It uses file .clang-format. In order to run it you have to download the tool with the instructions provided by us on our wiki page: [https://github.com/JaroslawWiosna/regionalizer/wiki/Clang](https://github.com/JaroslawWiosna/regionalizer/wiki/Clang) .<br />

The rule is that you have to run it before each commit you make to the repository so we could keep consistency.
In order to run it you have to be one folder up(over) the repository file and you have to run exacly the following command in the console:
```sh
find regionalizer -iname *.hpp -o -iname *.cpp | xargs clang-format -i -style=file
```

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

