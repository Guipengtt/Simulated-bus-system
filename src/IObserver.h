#ifndef SRC_IOBSERVER_H_
#define SRC_IOBSERVER_H_

#include "src/data_structs.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is a abstract class which can be derivable by concrete observer class
 */
class IObserver {
 public:
   /**
    * @brief This function is to Update BusData
    */
    virtual void Notify(BusData* bdata) = 0;
};
#endif  // SRC_IOBSERVER_H_
