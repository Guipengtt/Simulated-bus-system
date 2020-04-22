#include "src/my_r_local_simulator.h"

#include <vector>
#include <list>
#include "src/bus.h"
#include "src/stop.h"
#include "src/route.h"
#include "src/rtest_passenger_generator.h"

bool rLocalSimulator::Start() {
  simulation_time_elapsed = 0;  // init, but also allows restart

  // int num_round_trips = 10;
  int num_round_trips = 1;
  for (int i = 0; i < num_round_trips; i++) {
    time_since_last_bus_generation.push_back(0);
  }

  Stop ** CC_NR_stops = new Stop *[7];
  Stop ** CC_SR_stops = new Stop *[5];
  std::list<Stop *> CC_NR_stops_list;
  std::list<Stop *> CC_SR_stops_list;

  // northe stop
  Stop * stop_CC_NR_1 = new Stop(0, 44.973179, -93.235385);
  Stop * stop_CC_NR_2 = new Stop(1, 44.975411, -93.236190);
  Stop * stop_CC_NR_3 = new Stop(2, 44.976730, -93.235383);
  Stop * stop_CC_NR_4 = new Stop(3, 44.980475, -93.234585);
  Stop * stop_CC_NR_5 = new Stop(4, 44.977339, -93.227832);
  Stop * stop_CC_NR_6 = new Stop(5, 44.975447, -93.226302);
  Stop * stop_CC_NR_7 = new Stop(6, 44.973571, -93.230222);

  // south stop
  Stop * stop_CC_SR_1 = new Stop(0, 44.973571, -93.230222);
  Stop * stop_CC_SR_2 = new Stop(1, 44.971452, -93.230271);
  Stop * stop_CC_SR_3 = new Stop(2, 44.970441, -93.230563);
  Stop * stop_CC_SR_4 = new Stop(3, 44.971720, -93.237246);
  Stop * stop_CC_SR_5 = new Stop(4, 44.973179, -93.235385);


  CC_NR_stops_list.push_back(stop_CC_NR_1);
  CC_NR_stops_list.push_back(stop_CC_NR_2);
  CC_NR_stops_list.push_back(stop_CC_NR_3);
  CC_NR_stops_list.push_back(stop_CC_NR_4);
  CC_NR_stops_list.push_back(stop_CC_NR_5);
  CC_NR_stops_list.push_back(stop_CC_NR_6);
  CC_NR_stops_list.push_back(stop_CC_NR_7);

  CC_SR_stops_list.push_back(stop_CC_SR_1);
  CC_SR_stops_list.push_back(stop_CC_SR_2);
  CC_SR_stops_list.push_back(stop_CC_SR_3);
  CC_SR_stops_list.push_back(stop_CC_SR_4);
  CC_SR_stops_list.push_back(stop_CC_SR_5);

  CC_NR_stops[0] = stop_CC_NR_1;
  CC_NR_stops[1] = stop_CC_NR_2;
  CC_NR_stops[2] = stop_CC_NR_3;
  CC_NR_stops[3] = stop_CC_NR_4;
  CC_NR_stops[4] = stop_CC_NR_5;
  CC_NR_stops[5] = stop_CC_NR_6;
  CC_NR_stops[6] = stop_CC_NR_7;

  CC_SR_stops[0] = stop_CC_SR_1;
  CC_SR_stops[1] = stop_CC_SR_2;
  CC_SR_stops[2] = stop_CC_SR_3;
  CC_SR_stops[3] = stop_CC_SR_4;
  CC_SR_stops[4] = stop_CC_SR_5;

  double * CC_NR_distances = new double[6];
  double * CC_SR_distances = new double[4];

  CC_NR_distances[0] = 1;
  CC_NR_distances[1] = 2;
  CC_NR_distances[2] = 3;
  CC_NR_distances[3] = 4;
  CC_NR_distances[4] = 5;
  CC_NR_distances[5] = 6;

  CC_SR_distances[0] = 1;
  CC_SR_distances[1] = 2;
  CC_SR_distances[2] = 3;
  CC_SR_distances[3] = 4;
  CC_SR_distances[4] = 5;

  std::list<double> CC_NR_probs;
  std::list<double> CC_SR_probs;

  CC_NR_probs.push_back(.3);
  CC_NR_probs.push_back(.4);
  CC_NR_probs.push_back(.1);
  CC_NR_probs.push_back(.02);
  CC_NR_probs.push_back(.25);
  CC_NR_probs.push_back(.34);
  CC_NR_probs.push_back(0);

  CC_SR_probs.push_back(.35);
  CC_SR_probs.push_back(.1);
  CC_SR_probs.push_back(.33);
  CC_SR_probs.push_back(.04);
  CC_SR_probs.push_back(0);


  RtestPassengerGenerator * CC_NR_generator =
  new RtestPassengerGenerator (CC_NR_probs, CC_NR_stops_list);
  RtestPassengerGenerator * CC_SR_generator =
  new RtestPassengerGenerator (CC_SR_probs, CC_SR_stops_list);


  Route * CC_NR = new Route("Campus Connector - Eastbound",
  CC_NR_stops, CC_NR_distances, 7, CC_NR_generator);
  Route * CC_SR = new Route("Campus Connector - Westbound",
  CC_SR_stops, CC_SR_distances, 5, CC_SR_generator);

  prototype_routes_.push_back(CC_NR);
  prototype_routes_.push_back(CC_SR);

  prototype_routes_[0]->Report(std::cout);
  prototype_routes_[1]->Report(std::cout);

  bus_counters.push_back(10000);


  bus_start_timings.push_back(10);

  return true;
}

bool rLocalSimulator::Update() {
  simulation_time_elapsed++;
  std::cout << "~~~~~~~~~~~~~ The time is now " << simulation_time_elapsed;
  std::cout << " ~~~~~~~~~~~~~" << std::endl;

  std::vector<int>::iterator bus_gen_timing_iter = bus_start_timings.begin();
  std::vector<int>::iterator bus_counter_iter = bus_counters.begin();
  std::vector<Route *>::iterator prototype_route_iter =
  prototype_routes_.begin();

  for (std::vector<int>::iterator it = time_since_last_bus_generation.begin();
      it != time_since_last_bus_generation.end();
      it++, bus_gen_timing_iter++, bus_counter_iter++) {
      (*it)++;

    if (0 >= (*bus_gen_timing_iter)) {
      Route * outbound = (*prototype_route_iter);
      prototype_route_iter++;
      Route * inbound = (*prototype_route_iter);
      prototype_route_iter++;
      active_buses_.push_back(new Bus(std::to_string((*bus_counter_iter)),
                                  outbound->Clone(), inbound->Clone(), 60, 1));
      (*bus_counter_iter)++;
      (*bus_gen_timing_iter) = 10;
    } else {
      prototype_route_iter++;
      prototype_route_iter++;
      (*bus_gen_timing_iter)--;
    }
  }

  for (std::list<Bus *>::iterator bus_iter = active_buses_.begin();
      bus_iter != active_buses_.end(); bus_iter++) {
    // update bus
    (*bus_iter)->Update();
    // bus report
    (*bus_iter)->Report(std::cout);
  }
  for (std::vector<Route *>::iterator route_iter = prototype_routes_.begin();
      route_iter != prototype_routes_.end(); route_iter++) {
    // update stop
    (*route_iter)->Update();
    (*route_iter)->Report(std::cout);
  }
  return true;
}
