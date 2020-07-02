#include <iostream>
#include "RPNCalculator.hpp"
#include <string>
using namespace std;


/* INPUT: No input
   Modify: Sets the top pointer to NULL
   Output: No output */
RPNCalculator::RPNCalculator() {

  stackHead = NULL;

};

/* INPUT: No INPUT
   Modify: Deletes the stack
   Output: No output */
RPNCalculator::~RPNCalculator() {

    while(stackHead->next != NULL) {

      pop();

    }

    stackHead = NULL;
};


/* INPUT: No input
   Modify: No modification
   Output: Boolean value (determines whether stack is empty) */
bool RPNCalculator::isEmpty() {

  if (stackHead == NULL) {

    return 1;

  }

  else {

    return 0;

  }
};

/*INPUT: A float datatype
  Modify: Inserts a node at the top of the stack with the input data
  OUTPUT: No output */
void RPNCalculator::push(float number) {

  Operand* Node = new Operand;

  Node->number = number;

  if (stackHead != NULL) {

    Node->next = stackHead;

    stackHead = Node;

  } else {

    stackHead = Node;

  }

};
