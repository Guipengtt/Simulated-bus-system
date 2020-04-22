
#ifndef SRC_PASSENGER_H_
#define SRC_PASSENGER_H_

#include <iostream>
#include <string>
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class is to generate passenger basic information
 */
class Passenger {  // : public Reporter {
 public:
    /**
    * @brief This is constructor
    */
    explicit Passenger(int = -1, std::string = "Nobody");
    /**
    * @brief This is function is to update passenger information
    */
    void Update();
    /**
    * @brief This is function is to load passenger to bus
    */
    void GetOnBus();
    /**
    * @brief This is function is to get total wait
    */
    int GetTotalWait() const;
    /**
    * @brief This is function is to check the passenger whether on bus 
    */
    bool IsOnBus() const;
    /**
    * @brief This is function is to get passenger destination
    */
    int GetDestination() const;
    /**
    * @brief This is function is to get passenger report
    */
    void Report(std::ostream&) const;

 private:
  std::string name_;
  int destination_stop_id_;
  int wait_at_stop_;
  int time_on_bus_;
  int id_;
  static int count_;  // global count, used to set ID for new instances
};
#endif  // SRC_PASSENGER_H_
