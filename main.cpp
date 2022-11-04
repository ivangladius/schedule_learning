
#include <iostream>

#include "sched.hpp"
#include "edf.hpp"

int main() {

  Sched * edf1 = new EDF({ {9,2}, {7,4}, {1,6} });

  edf1->add_task({130, 9});

  edf1->debug_task_list();

  std::cout << std::endl;

  edf1->calc();
  
  edf1->debug_task_list();

  return 0;
  
}
