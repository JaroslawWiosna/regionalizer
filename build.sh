#!/usr/bin/env bash

cmake -H. -B_builds
(cd _builds && make -j 2 )
