
#include "sched.hpp"
#include "edf.hpp"

#include <initializer_list>
#include <utility>
#include <algorithm>
#include <iostream>

EDF::EDF() : Sched{ } {}

EDF::EDF(int y, int x) : Sched{ y, x } {}

EDF::EDF(std::initializer_list<task_t> task_list)
    : Sched{ task_list } {}

EDF::~EDF() {}

void EDF::calc() {
  // sort task list in priority order
  std::sort(task_list.begin(), task_list.end(),
            [](const task_t& a, const task_t& b) -> bool
            {
              return a.D < b.D;
            });

  // calculate the correct order of task for exp:
  // 111334331143131 ....
  // where 1 = T1(x1,y1) ( Task 1), 2 = T2(x2, y2) ( Task 2), ....

  for (auto& t : task_list) 
    t.counter = t.D;

  // deadlines
  std::vector<double> task_deadline;
  for (const auto& t : task_list) {
    for (int i = 1; i <= 5; ++i) {
      task_deadline.push_back(t.D * i);
    }
    deadlines.push_back(task_deadline);
    task_deadline.clear();
  }

  int i = 1;
  std::cout << "Deadlines: \n";
  for (const auto& d : deadlines) {
    std::cout << "Task " << i << ": ";
    for (const auto& e : d)
      std::cout << e << " ";
    ++i;
    std::cout << "\n";
  }


 }

void EDF::verify() { return; }

void EDF::display() { return; }



