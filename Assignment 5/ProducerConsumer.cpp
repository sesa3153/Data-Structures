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


/* INPUT: No input
   Modify: No Modification
   OUTPUT: returns a boolean value that determines whether the array is Full */
bool ProducerConsumer::isFull() {

  if ((queueEnd+1)%SIZE == queueFront) {

    return 1;

  } else {

    return 0;

  }

};

/* INPUT: Takes in a string data type
   Modify: Appends the string to the rear of the queue if it is not full
   OUTPUT: No output */
void ProducerConsumer::enqueue(string item) {

  if(isFull()) {

    cout << "The Queue is full, cannot add new item" << endl;

  } else {

    queue[queueEnd] = item;

    queueEnd = (queueEnd+1)%SIZE;
  }

};


/* INPUT: No input
   Modify: Removes an element from the front of the queue
   OUTPUT: No output */
void ProducerConsumer::dequeue() {
  if (isEmpty()) {

    cout << "Queue empty, cannot dequeue an item" << endl;

  } else if (queueFront == queueEnd) {

      queue[queueFront] = "";

  } else {

    queue[queueFront] = "";
    queueFront = (queueFront + 1)%SIZE;

  }

};

nt ProducerConsumer::queueSize() {

  int length = queueEnd-queueFront;

  return length;

};

/* INPUT: No input
   Modify: No modification
   OUPUT: Returns the element in the front */
string ProducerConsumer::peek() {

  if (isEmpty()) {

    cout << "Queue is empty" << endl;

    return "";

  } else {

    return queue[queueFront];

  }

};
