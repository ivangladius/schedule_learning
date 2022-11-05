
#ifndef SCHED_HEADER
#define SCHED_HEADER

#include <vector>
#include <utility>
#include <cstdio>

class task_t {
public:
  double e;
  double D;
  int counter;
  task_t(double e, double D, int counter = 0)
      : e{ e }, D{ D }, counter{ counter } {}
};

typedef std::vector<task_t> task_list_t;

class Sched {

protected:
  int y, x;
  task_list_t task_list;
  std::vector<int> correct;
  std::vector<int> answer;
  std::vector<std::vector<double>> deadlines;

public:
  Sched();
  Sched(int, int);
  Sched(std::initializer_list<task_t>);
  virtual ~Sched();

  void add_task(const task_t&);

  std::vector<int>& get_answer();
  void add_to_answer(int);

  virtual void calc() = 0;
  virtual void verify() = 0;
  virtual void display() = 0;


  int read_tasks();

  void debug_task_list() const {
    int x = 1;
    for (const auto& t : task_list) {
      std::printf("T%d(%.2lf, %.2lf, c: %d) = %.3lf\n",
                  x, t.e, t.D, t.counter, (t.e/t.D));
      x++;
    }

  }
  
};

#endif
