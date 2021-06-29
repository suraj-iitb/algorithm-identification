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
  SwapNum = 0;

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

void SelectionSort()
{

  SwapNum = 0;
  for(int i = 0; i < N; ++i)
  {
    int mini = i;
    bool flag = false;

    for(int j = i; j < N; ++j)
    {
      if(A[j] < A[mini])
      {
	mini = j; 
	flag = true;	
      }
    }

    if(flag)
    {
      int tmp = A[i];
      A[i] = A[mini];
      A[mini] = tmp;

      ++SwapNum; 
    }
  }

  return;

}

int main()
{
  cin >> N;

  A = new int[N];

  for(int i = 0; i < N; ++i)
    cin >> A[i];

  //BubbleSort();
  SelectionSort();

  cout << A[0];
  for(int i = 1; i < N; ++i)
    cout << " " << A[i];

  cout << endl;
  cout << SwapNum << endl;

  delete [] A;


}
