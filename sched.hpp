
#ifndef SCHED_HEADER
#define SCHED_HEADER

#include <vector>
#include <utility>
#include <cstdio>

typedef std::pair<double, double> task_t;
typedef std::vector<std::pair<double, double>> task_list_t;

class Sched {
protected:
  std::vector<std::pair<double, double>> task_list;
public:
  Sched(std::initializer_list<task_t>);
  ~Sched();

  task_list_t& get_task_list() const;
  void set_task_list(const task_list_t&);


  void debug_task_list() const {
    int x = 1;
    for (const auto& t : task_list) {
      std::printf("T%d(%.2lf, %.2lf)\n",
                  x, t.first, t.second);
    }
  }
  
};

#endif
