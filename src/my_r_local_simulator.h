#ifndef SRC_MY_R_LOCAL_SIMULATOR_H_
#define SRC_MY_R_LOCAL_SIMULATOR_H_

#include <vector>
#include <string>
#include "src/simulator.h"

class rLocalSimulator : public Simulator {
 public:
  bool Start() override;
  bool Update() override;
 private:
  std::vector<int> bus_counters;
  std::vector<int> bus_start_timings;
  std::vector<int> time_since_last_bus_generation;
  int simulation_time_elapsed;
};

#endif  // SRC_MY_R_LOCAL_SIMULATOR_H_
