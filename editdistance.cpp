#include <iostream>
#include <string>
#include <cmath>

using  namespace std;

int checkDistance(string firstWord, string secondWord);

int main ()
{
  cout << checkDistance("#intention","#execution") << endl;
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
