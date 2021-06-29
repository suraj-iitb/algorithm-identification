#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> &A)
{
  for (vector<int>::size_type i = 0; i < A.size(); i++)
  {
    cout << A[i];
    if(i != A.size()-1)
      cout << " ";
  }
  cout << endl;
}

int main()
{
  vector<int> A;
  int temp;
  int num;

  cin >> num;
  for (int i = 0; i < num; i++)
  {
    cin >> temp;
    A.push_back(temp);
  }

  int v, j;
  // InsectionSort
  for (vector<int>::size_type i = 0; i < A.size(); i++)
  {
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v)
    {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
    printArray(A);
  }

  return 0;
}

