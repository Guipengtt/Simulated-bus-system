/**
 * @file bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_H_
#define SRC_BUS_H_

#include <iostream>
#include <list>
#include <string>

#include "src/data_structs.h"

#include "src/passenger.h"
#include "src/passenger_loader.h"
#include "src/passenger_unloader.h"
#include "src/route.h"
#include "src/stop.h"
#include "IObservable.h"

class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief This class is to generate bus basic information
  */
class Bus: public IObservable {
 public:
       Bus(std::string name, Route * out, Route * in, int capacity = 60,
                                          double speed = 1);
       /**
       * @brief This function check whether the bus finsish trip
       */
       bool IsTripComplete();
       /**
       * @brief This function is to load passengers
       */
       bool LoadPassenger(Passenger *);  // returning revenue delta
       /**
       * @brief This function is to Move bus
       */
       bool Move();
       /**
       * @brief This function is to Update bus information
       */
       void Update();
       /**
       * @brief This function is to Report bus information
       */
       void Report(std::ostream&);

       // Vis Getters
       /**
       * @brief This function is to Update bus data
       */
       void UpdateBusData();
       /**
       * @brief This function is to get bus data
       */
       BusData GetBusData() const;
       /**
       * @brief This function is to get bus name
       */
       std::string GetName() const { return name_; }
       /**
       * @brief This function is to get next stop
       */
       Stop * GetNextStop() const { return next_stop_; }
       /**
       * @brief This function is to get number of passenger
       */
       size_t GetNumPassengers() const { return passengers_.size(); }
       /**
       * @brief This function is to get capacity
       */
       int GetCapacity() const { return passenger_max_capacity_; }

 protected:
       int UnloadPassengers();  // returning revenue delta
       // bool Refuel();
       PassengerUnloader * unloader_;
       PassengerLoader * loader_;
       std::list<Passenger *> passengers_;
       int passenger_max_capacity_;
       // revenue collected from passengers, doesn't include
       // double revenue_;
       // passengers who pay on deboard
       // double fuel_;   // may not be necessary for our simulation
       // double max_fuel_;
       std::string name_;
       // could also be called "distance travelled in one time step"
       double speed_;
       Route * outgoing_route_;
       Route * incoming_route_;
       // when negative?, unload/load procedure occurs
       double distance_remaining_;
                            // AND next stop set
       Stop * next_stop_;
       // [DERIVED data] when BOTH routes are at end, trip
       // bool trip_complete_;
       // is complete
       // Vis data for bus
       BusData bus_data_;
};
#endif  // SRC_BUS_H_
