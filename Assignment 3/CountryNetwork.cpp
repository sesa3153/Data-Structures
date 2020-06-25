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

void CountryNetwork::transmitMsg(string reciever, string msg)
{
  int checker = 0;
  Country* current3 = head;
  if (current3->next == NULL)
  {
    cout << "Empty List" << endl;
  }
  while (current3->next != NULL)
  {
    if (current3->name == reciever)
    {
      checker = 1;
    }
    current3 = current3->next;
  }
  if(checker == 0)
  {
    cout << "Country not found" << endl;
  }
  else
  {
    current3 = head;
    while(current3->name != reciever)
    {
      current3->message = msg;
      current3->numberMessages++;
      cout << current3->name << " [# messages recieved: " << current3->numberMessages << "] recieved: " << current3->message << endl;
      current3 = current3->next;
    }
      current3->message = msg;
      current3->numberMessages++;
      cout << current3->name << " [# messages recieved: " << current3->numberMessages << "] recieved: " << current3->message << endl;
  }


};



void CountryNetwork::printPath()
{
  Country* current4 = head;
  cout << "== CURRENT PATH ==" << endl;
  while(current4->next != NULL)
  {
    cout << current4->name <<" -> ";
    current4 = current4->next;
  }
  cout << current4->name <<" -> "<< "NULL"<< endl;
};
