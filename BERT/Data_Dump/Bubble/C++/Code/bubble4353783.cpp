#include <iostream>
#include <climits>

using namespace std;

int *A;
int N;
int SwapNum;

void BubbleSort()
{
  bool flag = true;
  int i = 0;

  do
  {

    flag = false;
    for(int j = N - 1; j >= i + 1; --j)
    {
      if(A[j] < A[j-1])
      {
	int tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;

	flag = true;
	++SwapNum;
      }

    }

    ++i;


  }while(flag);

  return;
}

int main()
{
  cin >> N;

  A = new int[N];

  for(int i = 0; i < N; ++i)
    cin >> A[i];

  BubbleSort();

 cout << A[0];
 for(int i = 1; i < N; ++i)
     cout << " " << A[i];

  cout << endl;
  cout << SwapNum << endl;

  delete [] A;


}

