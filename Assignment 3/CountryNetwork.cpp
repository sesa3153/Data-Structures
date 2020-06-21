CountryNetwork::CountryNetwork()
{
  list<Country> Countries(7);
  Countries.begin() = NULL;
  head = Countries.begin();
}

CountryNetwork::InsertCountry(Country* previous, string countryName)
{

  if (previous == NULL)
  {
    previous++;
    previous->name = countryName;
    cout << "adding: " << countryName << "(Head)" << endl;
  }
  else
  {
    previous++;
    previous->name = countryName;
    cout << "adding: " << countryName << "(prev: " << previous->name << ")" << endl;
  }
}

CountryNetwork::loadDefaultSetup()
{
  InsertCountry(head, "United States");
  InsertCountry(head++, "Canada");
  InsertCountry(head++, "Brazil");
  InsertCountry(head++, "India");
  InsertCountry(head++, "China");
  InsertCountry(head++, "Austraila");
}
