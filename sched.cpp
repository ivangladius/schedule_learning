
#include "sched.hpp"

#include <ncurses.h>

#include <utility>
#include <vector>
#include <iostream>

#include <ncurses.h>
#include <curses.h>
#include <string.h>
#include <stdlib.h>

#include "colors.hpp"


Sched::Sched() {}

Sched::Sched(int y, int x) : y{ y }, x{ x } {}

Sched::Sched(std::initializer_list<task_t> task_list) {
  this->task_list.insert(this->task_list.end(), task_list.begin(), task_list.end());

  // init ncurses
  //
  //
//  debug_task_list();

  /*
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  noecho();
  nodelay(stdscr, TRUE);
  curs_set(0);
  */


}

Sched::~Sched() {
    // endwin();
}

void Sched::add_task(const task_t& task) {
    task_list.push_back(task);
}

std::vector<int>& Sched::get_answer() { return answer; }
void Sched::add_to_answer(int value) { answer.push_back(value); }


int Sched::read_tasks() {

  char number[3];

  cprint(fwhite, 2, 2, "How many tasks ( maximum 10): ");
  move(2, 32);

  int input;
  int n = 0;
  int ty, tx;

  do {

	input = getch();

	if (input == 10)
	  break;

	else if (input == KEY_BACKSPACE) {
	  getyx(stdscr, ty, tx);
	  // cprint(fred, 31, 31, "Curs: %d x %d", ty, tx);
	  if (tx < 31)
		continue;

	  // move(31, 0);
	  // clrtoeol();

	  cprint(bblue, 15, 15, "TRIGGER BACKSPACE: %c", input);
	  move(2, 32+n - 1);
	  n--;
	  echochar(' ');
	}
	else if ('0' <= (char)input && (char)input <= '9'){
	  cprint(bblue, 15, 15, "n : %d\tTRIGGER : %c", n, input);
	  move(2, 32+n);
	  echochar(input);
	  number[n] = (char)input;
	  cprint(byellow, 18, 18, "number: %s", number);
	  n++;
	  // number[n] = (char)input;
	}

  } while (n <= 20);


  cprint(fblue, 21, 21, "end n : %d", n);
  
  memset(number+n, 0, sizeof(number)/sizeof(number[0])); 


  if (n == 3 || n == 0 || atoi(number) <= 0 || atoi(number) > 10) {
	cprint(bred, 15, 15, "NUMBER MUST BE BEWTEEN 1 - 10 !!! ( Press ENTER ");
  }

  if (atoi(number) <= 10)
	cprint(bblue, 8, 8, "You entered: %d\n", atoi(number));

  return 0;

}







