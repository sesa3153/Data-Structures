#include <iostream>
#include "RPNCalculator.hpp"
#include <string>

using namespace std;

bool isNumber(string s)
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(!isdigit(s[i]) && s[i] != '.') return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

int main() {

RPNCalculator object;

cout << "Enter the operators and the operands ('+','*') in a postfix format"<<endl;

while(true) {

  cout << "#>";

  string input;

  getline(cin, input);

  if(isNumber(input)) {

    object.push(stof(input));

  } else if (input == "=") {

    break;

  } else if (!isNumber(input)) {

    object.compute(input);

  } else {

      cout << "invalid expression" << endl;

  }

}

if (object.isEmpty()) {

  cout << "No operands: nothing to evaluate" << endl;

} else if (object.getStackHead()->next != NULL) {

  cout << "Invalid expression" << endl;

} else {

  cout << object.peek()-> number << endl;

}

  return 0;
}
