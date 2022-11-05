
#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <ncurses.h>

#include "sched.hpp"
#include "edf.hpp"

#include "colors.hpp"

int menu() {
    cprint(fwhite, 4, 4, "WELCOME");
    cprint(fwhite, 6, 4, "Please Choose an Schedule you want to learn:");
    cprint(fwhite, 7, 4, "(Press key .. 0 for EDF, 1 for ....)");
    cprint(fwhite, 9, 8, "1 : EDF ( Earliest Deadline First )");
    refresh();
    int key = getch();

    clear();

    return key;
}

int main(int argc, char ** argv) {

  int y = atoi(argv[1]);
  int x = atoi(argv[2]);

  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  noecho();
  //nodelay(stdscr, TRUE);
  curs_set(0);
  init_colors();

  // MAIN LOOP

  uint8_t again = 0;

  do {

    clear();

    int choose = menu();

    Sched * sched;

    int read_status;

    switch (choose) {
    case '1':
      sched = new EDF(y, x);
      read_status = sched->read_tasks();
      break;
    }

    if (!read_status)

    getch();

  } while(again);

  getch();
  clear();
  cprint(bblue, 15, 15, "CLOSING..");
  getch();

  endwin();

  return 0;
  
}
