#/usr/bin/env bash

# steps to do:
#  source regionalizer-completion.bash 
#  echo $PATH
#  mkdir -p ~/bin
#  install ./_builds/regionalizer ~/bin/regionalizer

complete -W "--demo -N --number" regionalizer
