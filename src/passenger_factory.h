#ifndef SRC_PASSENGER_FACTORY_H_
#define SRC_PASSENGER_FACTORY_H_

#include <string>

#include "src/passenger.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
* @brief This class is to create a passenger factory
*/
class PassengerFactory {
 public:
  /**
  * @brief This function is to generate passenger
  */
  static Passenger * Generate(int, int);
 private:
  static std::string NameGeneration();
};
#endif  // SRC_PASSENGER_FACTORY_H_
