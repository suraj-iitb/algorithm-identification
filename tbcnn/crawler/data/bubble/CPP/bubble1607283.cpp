#include <iostream>
#include <vector>
using namespace std;



int main()
{
  vector<int> A;
  int N;
  int sw = 0;

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    int a;
    cin >> a;
    A.push_back(a);
  }

  for (int i = 0; i < N-1; i++)
  {
    for (int j = N-1; j >= i+1; j--)
    {
      if (A[j] < A[j-1])
      {
        sw++;
        int tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
      }
    }
  }

  for (int i = 0; i < N; i++)
  {
    cout << A[i];
    if (i != N-1) cout << ' ';
  }
  cout << endl;
  cout << sw << endl;
}
