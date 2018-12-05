#!/usr/bin/env bash

#xgettext --keyword=_ --language=C --add-comments --sort-output -o po/regionalizer.pot main.cpp
#msginit --input=po/regionalizer.pot --locale=pl --output=po/pl/regionalizer.po
#msgfmt --output-file=po/pl/regionalizer.mo po/pl/regionalizer.po

xgettext --keyword=_ --language=C --add-comments --sort-output -o po/regionalizer.pot src/main.cpp
msgmerge --update po/pl/regionalizer.po po/regionalizer.pot
msgfmt --output-file=po/pl/regionalizer.mo po/pl/regionalizer.po

