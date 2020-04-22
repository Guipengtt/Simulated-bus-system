
#ifndef SRC_SMALL_BUS_H_
#define SRC_SMALL_BUS_H_

#include <string>

#include "src/bus.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class is to create small bus
 */
class SmallBus: public Bus{
 public:
      /**
      * @brief This is constructor
      */
      SmallBus(std::string name, Route * out, Route * in,
      int capacity = 30, double speed = 1);
      /**
      * @brief This function is get report
      */
      void Report(std::ostream& out);
};
#endif  // SRC_SMALL_BUS_H_
