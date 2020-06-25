#include "CountryNetwork.hpp"
#include <iostream>
#include <list>
using namespace std;

CountryNetwork::CountryNetwork()
{

  head = NULL;

};

void CountryNetwork::insertCountry(Country* previous, string countryName)
{

  Country* node = new Country;
  Country* current;
  node->name = countryName;
  node->numberMessages = 0;

  if (previous != NULL)
  {
    current = previous;
    while(current -> next !=NULL)
    {
      current = current->next;
    }
    current->next = node;
    cout << "adding: " << countryName << " (prev: " << current->name << ")" << endl;
  }
  else
  {
    head = node;
    cout << "adding: " << countryName << " (Head)" << endl;
  }

};


