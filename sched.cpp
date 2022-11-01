
#include "sched.hpp"
#include <utility>
#include <vector>
#include <iostream>

Sched::Sched(std::initializer_list<task_t> task_list) {
  this->task_list.insert(this->task_list.end(), task_list.begin(), task_list.end());
}

Sched::~Sched() {}


