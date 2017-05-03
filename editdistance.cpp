#include <iostream>
#include <string>

using  namespace std;

int checkDistance(string firstWord, string secondWord);
int minimum(int a,int b,int c);

int main ()
{
  cout << checkDistance("#intention","#execution") << endl;
  return 0;
}

int checkDistance(string firstWord, string secondWord)
{
  int distance=0;
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
        matrix[i][j]=minimum(matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1]+(firstWord[i]==secondWord[j]?0:2));
    }
  }
  for (int i=0;i<firstWord.length();i++)
  {
    for (int j=0;j<secondWord.length();j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return distance;
}

int minimum(int a,int b,int c)
{
  if (a>b&&a>b)
    return a;
  if (b>c&&b>a)
    return b;
  if (c>a&&c>b)
    return c;
}
