#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct wordItem{
  string word;
  int count;
};

void resize(wordItem *& arr,int length);
void getStopWords(const char *ignoreWordFileName, string ignoreWords[]);
bool isStopWord(string word, string ignoreWords[]);
int getTotalNumberNonStopWords(wordItem uniqueWords[], int length);
void arraySort(wordItem uniqueWords[], int length);
void printNext10(wordItem uniqueWords[], int N, int totalNumWords);
bool checker(string word, wordItem uniqueWords[], int length);
int loca(string word2, wordItem array[], int length,int tracker);

int main(int argc,const char** argv)
{

  if (argc != 4)
  {
    cout<< "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWords.txt>" <<endl;
    exit(0);
  }



  string ignoreWords[50];

  int tracker = 0;

  int length = 100;
  
  int howmanytimes = 0;
  
  int location;
  
  string temp;
  
  string word2;
  
  wordItem* uniqueWords = new wordItem[length];

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
            if (length <= tracker)
            {
              resize(uniqueWords, length);
              length = 2*length;
            }

            location = loca(word2, uniqueWords, length);

            if(!checker(word2, uniqueWords, length))
            {
              uniqueWords[tracker].word = word2;
              uniqueWords[tracker].count = 1;
              tracker++;
            }
            else
            {
              uniqueWords[location].count++;
            }
          }
    }
  }
  
  TomSawyer.close();

int numberOfuniqueWords = getTotalNumberNonStopWords(uniqueWords, length);

arraySort(uniqueWords, length);

cout << "Array Doubled: " << howmanytimes << endl;
cout << "#"<<endl;
cout << "Unique non-common words: " << tracker << endl;
cout << "#" << endl;
cout << "Total non-common words: " << numberOfuniqueWords << endl;
printNext10(uniqueWords, stoi(argv[1]), numberOfuniqueWords);


  return 0;
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


void resize(wordItem *& arr, int length)
{
  wordItem *arr2 = new wordItem[length*2];
  for (int i; i<length; i++)
  {
    arr2[i] = arr[i];
  }
  delete[] arr;
  arr = arr2;
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length)
{

  int number = 0;
  for (int i = 0; i <length; i++)
  {
    number = number + uniqueWords[i].count;
  }
  return number;
}

void arraySort(wordItem uniqueWords[], int length)
{

  int j;
  int key;
  wordItem key2;
  for (int i = 1; i < length; i++)
  {
    key = uniqueWords[i].count;
    key2 = uniqueWords[i];
    j = i - 1;
    while (j >= 0 && key > uniqueWords[j].count)
    {
      uniqueWords[j+1] = uniqueWords[j];
      j = j - 1;
    }
    uniqueWords[j+1] = key2;
  }
}

void printNext10(wordItem uniqueWords[], int N, int totalNumWords)
{

  float prob;
  cout << "Probability of the next 10 words from rank " << N << endl;
  cout << "----------------------------------------------" <<endl;
  for (int i = (N); i < (N+10); i++)
  {
    prob = (float) (uniqueWords[i].count)/totalNumWords;
    cout << prob << " - " << uniqueWords[i].word << endl;
  }
}

int loca(string word2, wordItem array[], int length, int tracker)
{
  int loc = tracker;
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
