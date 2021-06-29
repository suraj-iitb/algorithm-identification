#include <iostream>
#include <climits>

using namespace std;

int *A;
int N;
int SwapNum;
int Count;

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

void InsertionSort(int g)
{

  for(int i = g; i < N; ++i)
  {
    int v = A[i];
    int j = i - g;

    while( j >= 0 && A[j] > v)
    {
      A[j + g] = A[j];
      j = j - g;
      ++Count;
    }
    A[j + g] = v;
  }

  return;
}

void ShellSort()
{

  Count = 0;

  int m = 0;
  int s = 1;

  while(N / s > 0)
  {
    s *= 2;
    ++m;
  }

  int G[N];

  for(int i = 0, s = 1; i < m; ++i, s *= 2)
    G[i] = N / s; 

  for(int i = 0; i < m; ++i)
    InsertionSort(G[i]);

  cout << m << endl;

  for(int i = 0; i < m; ++i) 
    cout << (i != 0 ? " " : "") << G[i];
  cout << endl;

  cout << Count << endl;

  for(int i = 0; i < N; ++i)
    cout << A[i] << endl;

  return;
}

int *L, *R;

void Merge(int left, int mid, int right)
{
  int n1 = mid - left;
  int n2 = right - mid;

  for(int i = 0; i < n1; ++i)
    L[i] = A[left+i];
  for(int i = 0; i < n2; ++i)
    R[i] = A[mid+i];

  R[n2] = L[n1] = INT_MAX;

  int i = 0, j = 0;

  for(int k = left; k < right; ++k, ++SwapNum)
    A[k] = (L[i] <= R[j]) ? L[i++] : R[j++];
}

void MergeSort(int left, int right)
{
  if(left + 1 < right)
  {
    int mid = (left + right) / 2;
    MergeSort(left, mid);
    MergeSort(mid, right);
    Merge(left, mid, right);

    //++SwapNum;
  }
}

int main()
{
  cin >> N;

  A = new int[N];
  L = new int[N];
  R = new int[N];

  for(int i = 0; i < N; ++i)
    cin >> A[i];

  SwapNum = 0;
  //BubbleSort();
  //SelectionSort();
  //ShellSort();

  MergeSort(0, N);

  cout << A[0];
  for(int i = 1; i < N; ++i)
    cout << " " << A[i];

  cout << endl;
  cout << SwapNum << endl;

  delete [] L;
  delete [] R;
  delete [] A;


}
