
#ifndef EDF_HEADER
#define EDF_HEADER

#include <initializer_list>
#include <utility>

#include "sched.hpp"

class EDF : public Sched {
public:
  EDF();
  EDF(int, int);
  EDF(std::initializer_list<task_t>);
  ~EDF();

  void calc() override;
  void verify() override;
  void display() override;

};

#endif
