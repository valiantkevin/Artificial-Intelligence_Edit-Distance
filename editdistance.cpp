#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>

using  namespace std;

//Classical Levenshtein
int checkDistance(string firstWord, string secondWord);
void dictionaryPrep(vector<string> *dictionary);

int main ()
{
  bool isInDictionary = 0;
  vector<string> dictionary;
  dictionaryPrep(&dictionary);
  queue<string> one;
  queue<string> two;
  string input;
  cin >> input;
  for (int i=0;i<dictionary.size();i++)
  {
    if (dictionary[i]==input)
    {
      isInDictionary=1;
      break;
    }
    if ((dictionary[i].length()-input.length())<=2||(input.length()-dictionary[i].length())<=2)
    {
      int distance = checkDistance("#"+input,"#"+dictionary[i]);
      if (distance==1)
        one.push(dictionary[i]);
      else if (distance==2)
        two.push(dictionary[i]);
    }
  }
  if (!isInDictionary)
  {
    while (one.size())
    {
      cout << one.front() << endl;
      one.pop();
    }
    while (!two.empty())
    {
      cout << two.front() << endl;
      two.pop();
    }
  }
  return 0;
}

int checkDistance(string firstWord, string secondWord)
{
  //matrix inizialization
  int matrix[firstWord.length()][secondWord.length()];
  matrix[0][0]=0;
  for (int i=1;i<firstWord.length();i++)
    matrix[i][0]=i;
  for (int i=1;i<secondWord.length();i++)
    matrix[0][i]=i;
  //counting every cell value
  for (int i=1;i<firstWord.length();i++)
  {
    for (int j=1;j<secondWord.length();j++)
    {
      matrix[i][j]=min(min(matrix[i-1][j]+1,matrix[i][j-1]+1),matrix[i-1][j-1]+(firstWord[i]==secondWord[j]?0:2));
    }
  }
  return matrix[firstWord.length()-1][secondWord.length()-1];
}

void dictionaryPrep(vector<string> *dictionary)
{
  ifstream file("originals.txt");
  string temp;
  while (!file.eof())
  {
    file >> temp;
    dictionary->push_back(temp);
  }
}
