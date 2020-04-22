/**
 * @file BUS_factory.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <vector>
#include <random>
#include <string>
#include <ctime>
#include "src/bus_factory.h"
#include "src/small_bus.h"
#include "src/regular_bus.h"
#include "src/large_bus.h"


std::random_device bev;
std::mt19937 rng(bev());
std::uniform_int_distribution<std::mt19937::result_type> dist1(1, 3);


static const int theSize[3] = {
  30, 60, 90
};

int state = 0;

// Factory pattern
// Bus* BusFactory::Generate(std::string name, Route* in,
//                             Route* out, double speed) {
//   int size = SizeGeneration();
//   if (size == 1) {
//     return new SmallBus(name, in, out, 30, speed);
//   } else if (size == 2) {
//     return new RegularBus(name, in, out, 60, speed);
//   } else {
//     return new LargeBus(name, in, out, 90, speed);
//   }
// }

// Refactor Factory by strategy pattern
Bus* BusFactory::Generate(std::string name, Route* in,
                            Route* out, double speed) {
    time_t curr_time;

    curr_time = time(NULL);
    tm* local_t = localtime(&curr_time);
    if (local_t->tm_hour >= 6 && local_t ->tm_hour <= 8) {
      std::cout << "Current time: " << local_t->tm_hour <<":"
      <<local_t->tm_min<< std::endl;
      std::cout << "Strategy 1 start: " << std::endl;
      if (state % 3 == 0) {
          std::cout << "Bus type: small" << std::endl;
          std::cout << "Bus capability: 30" << std::endl;
          state++;
          return new SmallBus(name, in, out, 30, speed);
      } else if (state % 3 == 1) {
          std::cout << "Bus type: regular" << std::endl;
          std::cout << "Bus capability: 60" << std::endl;
          state++;
          return new RegularBus(name, in, out, 60, speed);
      } else {
          std::cout << "Bus type: large" << std::endl;
          std::cout << "Bus capability: 90" << std::endl;
          state++;
          return new LargeBus(name, in, out, 90, speed);
      }
    } else if (local_t->tm_hour > 8 && local_t->tm_hour <= 15) {
        std::cout << "Current time: " << local_t->tm_hour <<":"
        <<local_t->tm_min<< std::endl;
        std::cout << "Strategy 2 start: " << std::endl;
        if (state % 3 == 0) {
          std::cout << "Bus type: large" << std::endl;
          std::cout << "Bus capability: 90" << std::endl;
          state++;
          return new LargeBus(name, in, out, 90, speed);
        } else if (state % 3 == 1) {
          std::cout << "Bus type: regular" << std::endl;
          std::cout << "Bus capability: 60" << std::endl;
          state++;
          return new RegularBus(name, in, out, 60, speed);
        } else {
          std::cout << "Bus type: large" << std::endl;
          std::cout << "Bus capability: 90" << std::endl;
          state++;
          return new LargeBus(name, in, out, 90, speed);
        }
    } else {
        std::cout << "Current time: " << local_t->tm_hour <<":"
        <<local_t->tm_min<< std::endl;
        std::cout << "Strategy 3 start: " << std::endl;
        if (state % 3 == 0) {
          std::cout << "Bus type: regular" << std::endl;
          std::cout << "Bus capability: 60" << std::endl;
          state++;
          return new RegularBus(name, in, out, 60, speed);
        } else if (state % 3 == 1) {
          std::cout << "Bus type: large" << std::endl;
          std::cout << "Bus capability: 90" << std::endl;
          state++;
          return new LargeBus(name, in, out, 90, speed);
        } else {
          std::cout << "Bus type: small" << std::endl;
          std::cout << "Bus capability: 30" << std::endl;
          state++;
          return new SmallBus(name, in, out, 30, speed);
        }
    }
}

int BusFactory::SizeGeneration() {
  int rand_int = dist1(rng);
  return rand_int;
}
