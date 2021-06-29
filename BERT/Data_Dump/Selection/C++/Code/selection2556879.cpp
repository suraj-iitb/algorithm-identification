#include<iostream>
using namespace std;

void selectionSort(int A[],int N);
void printList(int A[],int N);

int main()
{
  int N;
  cin >> N;
  int A[N];
  for(int i=0;i<N;i++) cin >> A[i];
  selectionSort(A,N);
  return 0;
}

void selectionSort(int A[],int N)
{
  int count = 0;
  for(int i=0;i<N;i++) {
    int minj = i;
    for(int j=i;j<N;j++) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }
    if(i != minj) {
      swap(A[i],A[minj]);
      count++;
    }
  }
  printList(A,N);
  cout << count << endl;
}


void printList(int A[],int N)
{
  for(int i=0;i<N-1;i++) cout << A[i] << " ";
  cout << A[N-1] << endl;
}
