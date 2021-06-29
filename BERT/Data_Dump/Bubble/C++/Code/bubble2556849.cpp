#include<iostream>
using namespace std;

int bubbleSort(int A[],int N);
void printList(int A[],int N);

int main()
{
  int ans,N;
  cin >> N;
  int A[N];
  for(int i=0;i<N;i++) cin >> A[i];
  ans = bubbleSort(A,N);
  return 0;
}

int bubbleSort(int A[],int N)
{
  int count = 0;
  int tmp;
  int flag = 1;
  while(flag) {
    flag = 0;
    for(int j=N-1;j>0;j--) {
      if(A[j] < A[j-1]) {
        count += 1;
        tmp = A[j-1];
        A[j-1] = A[j];
        A[j] = tmp;
        flag = 1;
      }
    }
  }
  printList(A,N);
  cout << count << endl;
  return count;
}


void printList(int A[],int N)
{
  for (int i = 0;i<N-1;i++) cout << A[i] << " ";
  cout << A[N-1] << endl;
}
