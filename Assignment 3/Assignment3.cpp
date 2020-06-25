#include <iostream>
#include "CountryNetwork.hpp"
using namespace std;

void displayMenu();


int main()
{
  int option = 0;
  string reciever = "";
  string msg = "";
  string countryName = "";
  string prevCountry= "";
  CountryNetwork object;
    while(option != 5)
    {
      displayMenu();
      cin >> option;
      if (option<6) {
        switch(option) {
          case 1:
            object.loadDefaultSetup();
            object.printPath();
            break;
          case 2:
            object.printPath();
            break;
          case 3:
            cout << "Enter the name of the country to recieve the message: ";
            cin.ignore();
            cin >> reciever;
            cout << "Enter the message to send: ";
            cin.ignore();
            cin >> msg;
            object.transmitMsg(reciever, msg);
            break;
          case 4:
            cout << "Enter the name of the country: " << endl;
            cin.ignore();
            cin >> countryName;
            cout << "Enter the name of the previous country or First: " << endl;
            cin.ignore();
            cin >> prevCountry;
            while (object.searchNetwork(prevCountry) == NULL)
            {
              cout <<"INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
              cin >> prevCountry;
            }
            object.insertCountry(object.searchNetwork(prevCountry), countryName);
            object.printPath();
          case 5:
          cout << "Quitting..." << endl;
        }
      }
      else {
        cout << "Invalid Input: Try Again" << endl;
      }
    }
    cout << "GOODBYE!" << endl;

}


void displayMenu()
{
  cout << "Select a numerical option:" << endl;
  cout << "+=====Main Menu=========+" << endl;
  cout << " 1. Build Network " << endl;
  cout << " 2. Print Network Path " << endl;
  cout << " 3. Transmit Message " << endl;
  cout << " 4. Add Country " << endl;
  cout << " 5. Quit " << endl;
  cout << "+-----------------------+" << endl;
  cout << "#> ";
}
