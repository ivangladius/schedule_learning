
#include "sched.hpp"
#include "edf.hpp"

#include <initializer_list>
#include <utility>
#include <algorithm>


EDF::EDF() : Sched{ } {}

EDF::EDF(std::initializer_list<task_t> task_list)
    : Sched{ task_list } {}

EDF::~EDF() {}

void EDF::calc() {
  // sort task list in priority order
  std::sort(task_list.begin(), task_list.end(),
            [](const task_t& a, const task_t& b) -> bool
            {
              return (a.first/a.second) < (b.first/b.second);
            });

  // calculate the correct order of task for exp:
  // 111334331143131 ....
  // where 1 = T1(x1,y1) ( Task 1), 2 = T2(x2, y2) ( Task 2), ....

  

}

void EDF::verify() { return; }

void EDF::display() { return; }



