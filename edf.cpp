
#include "sched.hpp"


EDF::EDF() : Sched() {}
EDF::EDF(const std::initializer_list<task_t>& task_list)
    : Sched(task_list) {}
