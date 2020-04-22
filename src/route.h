

#ifndef SRC_ROUTE_H_
#define SRC_ROUTE_H_

#include <list>
#include <iostream>
#include <string>

#include "./data_structs.h"

#include "./passenger_generator.h"
#include "./stop.h"

class PassengerGenerator;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class is to route
 */
class Route {
 public:
 /**
 * @brief This class is to route
 */
  Route(std::string name, Stop ** stops, double * distances, int num_stops,
        PassengerGenerator *);
 /**
 * @brief This function is to clone route
 */
  Route * Clone();
 /**
 * @brief This funciton is to update route information
 */
  void Update();
 /**
 * @brief This function is to report route information
 */
  void Report(std::ostream&);
 /**
 * @brief This function is to check wheather in the end
 */
  bool IsAtEnd() const;
 /**
 * @brief This function is to get previous stop
 */
  Stop *  PrevStop();  // Returns stop before destination stop
 /**
 * @brief This function is Change destination_stop_ to next stop
 */
  void ToNextStop();   // Change destination_stop_ to next stop
 /**
 * @brief This function is Get pointer to next stop
 */
  Stop * GetDestinationStop() const;    // Get pointer to next stop
 /**
 * @brief This function is get total route distance
 */
  double GetTotalRouteDistance() const;
 /**
 * @brief This function is get next stop distance
 */
  double GetNextStopDistance() const;

  // Vis Getters
 /**
 * @brief This function is get route name
 */
  std::string GetName() const { return name_; }
 /**
 * @brief This function is get stops vector
 */
  std::list<Stop *> GetStops() const { return stops_; }
 /**
 * @brief This function is update route data
 */
  void UpdateRouteData();
 /**
 * @brief This function is to get route data
 */
  RouteData GetRouteData() const;


 private:
  int GenerateNewPassengers();       // generates passengers on its route
  PassengerGenerator * generator_;
  std::list<Stop *> stops_;
  std::list<double> distances_between_;  // length = num_stops_ - 1
  std::string name_;
  int num_stops_;
  int destination_stop_index_;  // always starts at zero, no init needed
  Stop * destination_stop_;
  // double trip_time_; // derived data - total distance travelled on route

  RouteData route_data_;
};
#endif  // SRC_ROUTE_H_
