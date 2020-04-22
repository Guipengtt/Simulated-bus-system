
#ifndef SRC_STOP_H_
#define SRC_STOP_H_

#include <list>
#include <iostream>

#include "src/bus.h"
#include "src/passenger.h"

class Bus;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class is to create stop
 */
class Stop {
 public:
  /**
  * @brief This is constructor
  */
  explicit Stop(int, double = 44.973723, double = -93.235365);
  /**
  * @brief This function is to load passengers
  */
  int LoadPassengers(Bus *);  // Removing passengers from stop
  // and onto a bus
  /**
  * @brief This function is to add passengers
  */
  int AddPassengers(Passenger *);  // Adding passengers
  // to the stop (from the generator)
  /**
  * @brief This function is to update stop information
  */
  void Update();
  /**
  * @brief This function is to get stop id
  */
  int GetId() const;
  /**
  * @brief This function is to get report
  */
  void Report(std::ostream&) const;

  // Vis Getters
  /**
  * @brief This function is to get longitude
  */
  double GetLongitude() const { return longitude_; }
  /**
  * @brief This function is to get latitude
  */
  double GetLatitude() const { return latitude_; }
  /**
  * @brief This function is to get number of passenger present
  */
  size_t GetNumPassengersPresent() { return passengers_.size(); }

 private:
  int id_;
  std::list<Passenger *> passengers_;  // considered array, vector, queue, list
  double longitude_;
  double latitude_;  // are we using long/lat coords?
  // derived information - not needed depending on passengers_
  // data structure implementation?
  // int passengers_present_;
};
#endif  // SRC_STOP_H_
