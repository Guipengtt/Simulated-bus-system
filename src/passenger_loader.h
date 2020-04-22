#ifndef SRC_PASSENGER_LOADER_H_
#define SRC_PASSENGER_LOADER_H_

#include <list>
#include "./passenger.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
* @brief This class is to create a passenger loader object
*/
class PassengerLoader {
 public:
  // LoadPassenger returns the number of passengers added to the bus.
  // Currently this is either one or zero: either passenger was added or they
  // weren't.
  // This was a design decision. We don't know if we should allow the adding of
  // multiple passengers at a time
  // This allows us to change the Passenger Loader without having to change
  // the Bus.
  /**
  * @brief This function is to load passenger
  */
  bool LoadPassenger(Passenger * new_passenger, int max_pass,
                    std::list<Passenger *> * passengers);
};
#endif  // SRC_PASSENGER_LOADER_H_
