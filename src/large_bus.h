#ifndef SRC_LARGE_BUS_H_
#define SRC_LARGE_BUS_H_

#include <string>

#include "src/bus.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
* @brief This class is to create a largeBus object
*/
class LargeBus: public Bus{
 public:
      /**
       * @brief This is constructor
       */
      LargeBus(std::string name, Route * out, Route * in, int capacity = 90,
                                                double speed = 1);
      /**
       * @brief This is report function
       */
      void Report(std::ostream& out);
};

#endif  // SRC_LARGE_BUS_H_
