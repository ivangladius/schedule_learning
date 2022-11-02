
#ifndef SCHED_HEADER
#define SCHED_HEADER

#include <vector>
#include <utility>
#include <cstdio>

typedef std::pair<double, double> task_t;
typedef std::vector<task_t> task_list_t;

class Sched {

protected:
  task_list_t task_list;
  std::vector<int> answer;

public:
  Sched();
  Sched(std::initializer_list<task_t>);
  virtual ~Sched();

  task_list_t& get_task_list();
  void set_task_list(const task_list_t&);

  void add_task(const task_t&);

  std::vector<int>& get_answer();
  void add_to_answer(int);

  void debug_task_list() const {
    int x = 1;
    for (const auto& t : task_list) {
      std::printf("T%d(%.2lf, %.2lf)\n",
                  x, t.first, t.second);
      x++;
    }

  }
  
};

#endif
