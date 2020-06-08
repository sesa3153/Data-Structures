#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct wordItem{
  string word;
  int count;
};

void resize(string arr[],int length);
void getStopWords(const char *ignoreWordFileName, string ignoreWords[]);
bool isStopWord(string word, string ignoreWords[]);
int getTotalNumberNonStopWords(wordItem uniqueWords[], int length);

int main(int argc,const char** argv)
{

  if (argc != 4)
  {
    cout<< "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWords.txt>" <<endl;
    exit(0);
  }



  string ignoreWords[50];

  string unique[100];

  int tracker = 0;

  int length;
  
  int length2;
  
  int location;
  
  string temp;
  
  string word2;

  getStopWords(argv[3], ignoreWords);

  ifstream TomSawyer;

  TomSawyer.open(argv[2]);
  if(TomSawyer.is_open())
  {
    while (TomSawyer >> word2)
    {
      cout << word2 <<endl;
          if (!isStopWord(word2, ignoreWords))
          {
            length = sizeof(uniqueWords)/sizeof(uniqueWords[0]);
            if (length < tracker)
            {
              resize(uniqueWords, length);
            }
            length2 = sizeof(uniqueWords)/sizeof(uniqueWords[0]);

            location = loca(word2, uniqueWords, length2);

            if(!checker(word2, uniqueWords, length2))
            {
              uniqueWords[tracker].word = word2;
              uniqueWords[tracker].count = 1;
              tracker++;
            }
            else
            {
              uniqueWords[location].count++;
            }
            cout << uniqueWords[tracker].count <<endl;
          }
    }
  }



}

// Functions
void getStopWords(const char *ignoreWordFileName, string ignoreWords[])
{

  ifstream File1;
  int i =0;
  File1.open(ignoreWordFileName);
  if (File1.is_open())
  {
    string temp;
    while(getline(File1,temp))
    {
      ignoreWords[i] = temp;
      i++;
    }
    File1.close();
  } else
  {
    cout<< "Failed to Open" << endl;
  }
}


bool isStopWord(string word, string ignoreWords[])
{
  bool IsIgnoreWord = 0;
  for (int j =0; j < 50; j++)
  {
    if (ignoreWords[j] == word)
    {
      IsIgnoreWord = 1;
    }
  }
  return IsIgnoreWord;
}


void resize(string arr[], int length)
{
  string arr2[2*length];
  for (int i; i<length; i++)
  {
    arr2[i] = arr[i];
  }
  delete[] arr;
  arr = arr2;
}

int loca(string word2, wordItem array[], int length)
{
  int loc;
  for (int g = 0; g < length; g++)
  {
    if (word2 == array[g].word)
    {
      loc = g;
    }
  }
  return loc;
}

bool checker(string word, wordItem uniqueWords[], int length)
{
  bool val = 0;
  for (int i = 0; i < length; i++)
  {
    if (word == uniqueWords[i].word)
    {
      val = 1;
    }
  }
  return val;
}
