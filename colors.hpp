
#ifndef NCURS_COLOR_HEADER
#define NCURS_COLOR_HEADER

#include <ncurses.h>
#include <stdarg.h>

enum Color {
  fred = 1,
  fgreen,
  fblue,
  fyellow,
  fpink,
  fblack,
  fwhite,
  fcyan,

  bred,
  bgreen,
  bblue,
  byellow,
  bpink,
  bblack,
  bwhite,
  bcyan,

  reset
};

void init_colors();
int cprint(enum Color color, int y, int x, const char *format, ...);
#endif
