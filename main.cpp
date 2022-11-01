
#include <iostream>
#include "sched.hpp"

int main() {
  Sched sched1({{2,4}, {7, 3}, {8, 19}});

  sched1.debug_task_list();

  
}
