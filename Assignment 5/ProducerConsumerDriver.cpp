#include <iostream>
#include "ProducerConsumer.hpp"
#include <string>
using namespace std;


void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
  cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main() {

int option;

int number;

int number2;

int i = 0;

int j = 0;

string item;

ProducerConsumer object;

while (option != 3) {

  menu();

  cin >> option;

  switch(option) {

    case 1:

      cout << "Enter the number of items to be produced: "<< endl;

      cin >> number;

      while(i<number) {

        cout << "Item: "<< endl;

        cin >> item;

        object.enqueue(item);

        cout << "Adding " << item << " to queue" << endl;

        i++;

      }
      break;
    case 2:

      cout << "Enter the number of items to be consumed: " << endl;

      cin >> number2;

      if (number2 > SIZE) {

        number2 = SIZE;
        cout << "No more Items to consume. You've only consumed what's below: " <<endl;
      }

      while(number2 > j) {

        cout << "Consumed: " << object.peek() << endl;

        object.dequeue();

        j++;

      }
      break;
    case 3:

      cout << "Number of items in the queue is: " << object.queueSize() << endl;
      break;
  }


}


  return 0;
}
