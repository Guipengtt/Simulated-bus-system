#ifndef SRC_PASSENGER_UNLOADER_H_
#define SRC_PASSENGER_UNLOADER_H_
#include <list>
#include "src/passenger.h"
#include "src/stop.h"
class Stop;
class Passenger;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
* @brief This class is to create a passenger unloader object
*/
class PassengerUnloader {
 public:
  // UnloadPassengers returns the number of passengers removed from the bus.
  /**
  * @brief This function is to unload passenger
  */
  int UnloadPassengers(std::list<Passenger*>* passengers,
  Stop * current_stop);
};
#endif  // SRC_PASSENGER_UNLOADER_H_


