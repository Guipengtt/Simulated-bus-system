

#ifndef SRC_RANDOM_PASSENGER_GENERATOR_H_
#define SRC_RANDOM_PASSENGER_GENERATOR_H_

#include <list>
#include <random>
#include <ctime>

#include "src/passenger_generator.h"
#include "src/stop.h"

class Stop;  // forward declaration
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class is to create RandomPassengerGenerator object
 */
class RandomPassengerGenerator : public PassengerGenerator{
 public:
  /**
  * @brief This is constructor
  */
  RandomPassengerGenerator(std::list<double>, std::list<Stop *>);
  /**
  * @brief This is function is to gerneate passenger
  */
  int GeneratePassengers() override;

 private:
  static std:: minstd_rand0 my_rand;
};

#endif  // SRC_RANDOM_PASSENGER_GENERATOR_H_
