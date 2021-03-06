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

/* INPUT: No input
   Modify: deletes the top most stack iteam if the stack is not empty
   OUTPUT: No output */
void RPNCalculator::pop() {

  if (stackHead != NULL) {

    Operand* temp = new Operand;

    temp = stackHead;

    stackHead = stackHead->next;

    delete temp;

  } else {

    cout << "Stack is empty, cannot pop an item" << endl;

  }

};


/* INPUT: No Input
   Modify: No modification
   OUTPUT: Returns the pointer to the top of the stack if it is not Empty */
Operand* RPNCalculator::peek() {

  if (stackHead != NULL) {

    return stackHead;

  } else {

      cout<< "Stack is empty" << endl;
      return NULL;

  }

};

/* INPUT: a string data that contains the operator
   Modify: deletes the nodes with the operands and pushed their result
   OUTPUT: a boolean value determining whether the computation was successful */
bool RPNCalculator::compute(string symbol) {

  if (isEmpty()) {

    cout << "err: not enough operands" << endl;

    return 0;

  } else {

    float number1 = stackHead->number;

    pop();

    if(stackHead == NULL) {

      cout << "err: not enough operands" << endl;

      push(number1);

      return 0;

    } else {

        float number2 = stackHead->number;

        pop();

        float result;

        if(symbol == "+") {

          result = number1 + number2;

          push(result);

          return 1;

        } else if (symbol == "*") {

          result = number1*number2;

          push(result);

          return 1;

        } else {

          cout << "err: invalid operation" << endl;

          return 0;

        }

    }

  }
};
