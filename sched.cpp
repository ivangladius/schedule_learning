
#include "sched.hpp"

#include <ncurses.h>

#include <utility>
#include <vector>
#include <iostream>


Sched::Sched() {}

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

task_list_t& Sched::get_task_list() {
    return task_list;
}

void Sched::set_task_list(const task_list_t& task_list) {
    this->task_list = task_list;
}

void Sched::add_task(const task_t& task) {
    task_list.push_back(task);
}

std::vector<int>& Sched::get_answer() { return answer; }
void Sched::add_to_answer(int value) { answer.push_back(value); }









