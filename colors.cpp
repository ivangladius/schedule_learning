
#include "colors.hpp"


void init_colors() {

  use_default_colors();
  start_color();


  init_pair(fred, COLOR_RED, -1);
  init_pair(fgreen, COLOR_GREEN, -1);
  init_pair(fblue, COLOR_BLUE, -1);
  init_pair(fyellow, COLOR_YELLOW, -1);
  init_pair(fpink, COLOR_MAGENTA, -1);
  init_pair(fblack, COLOR_BLACK, -1);
  init_pair(fwhite, COLOR_WHITE, -1);
  init_pair(fcyan, COLOR_CYAN, -1);

  init_pair(bred, COLOR_YELLOW, COLOR_RED);
  init_pair(bgreen, COLOR_BLACK, COLOR_GREEN);
  init_pair(bblue, COLOR_BLACK, COLOR_BLUE);
  init_pair(byellow, COLOR_BLACK, COLOR_YELLOW);
  init_pair(bpink, COLOR_BLACK, COLOR_MAGENTA);
  init_pair(bblack, COLOR_WHITE, COLOR_BLACK);
  init_pair(bwhite, COLOR_BLACK, COLOR_WHITE);
  init_pair(bcyan, COLOR_BLACK, COLOR_CYAN);

  init_pair(reset, -1, -1);
}


int cprint(enum Color color, int y, int x, const char *format, ...) {

  va_list args;
  va_start(args, format);


  move(y,x);
  attron(COLOR_PAIR(color));
  vw_printw(stdscr, format, args);
  attroff(COLOR_PAIR(color));

  va_end(args);

  return 0;
}


