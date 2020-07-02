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
