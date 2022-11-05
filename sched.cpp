
#include "sched.hpp"

#include <ncurses.h>

#include <utility>
#include <vector>
#include <iostream>

#include <ncurses.h>

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
  for (; n < 3; ++n) {

    input = getch();

    if (input == 10)
      break;

    else if (input == KEY_BACKSPACE) {
      cprint(bblue, 22, 22, "GOT BACKSPACE");
      n--;
      move(2, 32+n-1);
      delch();
      continue;
    }

    else if ((char)input >= '0' && (char)input <= '9' && n != 2) {
      number[n] = input;
      move(2, 32+n);
      echochar(input);
    }

  }

  if (n == 3 || n == 0 || atoi(number) <= 0 || atoi(number) > 10) {
    cprint(bred, 15, 15, "NUMBER MUST BE BEWTEEN 1 - 10 !!! ( Press ENTER ");
  }

  if (atoi(number) <= 10)
    cprint(bblue, 8, 8, "You entered: %d\n", atoi(number));

  return 0;

}








