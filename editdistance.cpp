#include <iostream>
#include <string>

using  namespace std;

int checkDistance(string firstWord, string secondWord);

int main ()
{
  cout << checkDistance("#intention","#execution") << endl;
  return 0;
}

int checkDistance(string firstWord, string secondWord)
{
  //matrix inizialization
  int matrix[firstWord.length()][secondWord.length()];
  matriks[0][0]=0;
  for (int i=1;i<firstWord.length())
    matrix[i][0]=i;
  for (int i=1;i<secondWord.length())
    matrix[0][i]=i;
  //counting every cell value
  for (int i=1;i<firstWord.length();i++)
  {
    for (int j=1;j<secondWord.length();j++)
    {

    }
  }
  return distance;
}
