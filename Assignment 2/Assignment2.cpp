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

  string temp;

  getStopWords(argv[3], ignoreWords);

  ifstream TomSawyer;

  TomSawyer.open(argv[2]);
  if(TomSawyer.is_open())
  {
    while (TomSawyer >> temp)
    {
      length = sizeof(unique)/sizeof(*unique);
      if (length < tracker)
      {
        resize(unique, length);
      }
      for (int k = 0; k < 50; k++)
      {
        if (temp != ignoreWords[k])
        {
          unique[tracker] = temp;
          tracker++;
        }
      }
    }
  }
cout << unique[0] <<endl;


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
