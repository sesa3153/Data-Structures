#include <iostream>
#include "ProducerConsumer.hpp"
#include <string>
using namespace std;

/* INPUT: No input
   Modify: sets the front and end queue to zero
   OUTPUT: No output */
ProducerConsumer::ProducerConsumer() {

  queueFront = 0;

  queueEnd = 0;

};

/* INPUT: No input
   Modify: No Modification
   OUTPUT: returns a boolean value that determines whether the array is empty */
bool ProducerConsumer::isEmpty() {

  if (queueEnd == 0 && queueFront == 0 ) {

    return 1;

  } else {

    return 0;

  }

};
