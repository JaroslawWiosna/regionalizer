#pragma once

#include <libintl.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define _(STRING) gettext(STRING)
