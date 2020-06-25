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

void CountryNetwork::loadDefaultSetup()
{

  insertCountry(head, "United States");

  insertCountry(head, "Canada");

  insertCountry(head, "Brazil");

  insertCountry(head, "India");

  insertCountry(head, "China");

  insertCountry(head, "Austraila");
};

Country* CountryNetwork::searchNetwork(string countryName)
{
  Country* temp2 = NULL;
  Country* temp3 = NULL;
  temp2 = head;
  while (temp2->next != NULL)
  {
    if(temp2->name == countryName)
    {
      temp3 = temp2;
    }
  }
  delete temp2;

  return temp3;
};
