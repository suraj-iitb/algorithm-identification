#include<iostream>

using namespace std;

const int MAX = 100000;
int count =0;
int array[MAX];
//void InsertionSort(int A[], int N);
//void bubbleSort(int A[], int N);
void selectionSort(int A[], int N);

int main(){
  int N;
  cin >> N;
  for(int i = 0; i < N;i++){
    cin >> array[i];
  }

  selectionSort(array,N);
  for(int i = 0; i < N;i++){
    if(i < N-1)
    cout << array[i] <<" ";
    else
    cout << array[i] << endl;
  }

cout << count << endl;

return 0;
}

void selectionSort(int A[], int N){

  for(int i = 0; i<=N-1;i++)
  {
    int minj = i;
    for(int j = i;j<=N-1;j++)
      if(A[j] < A[minj]){
        minj = j;

      }

    int k = A[minj];
    A[minj] = A[i];
    A[i] = k;
    if(i != minj)
      count++;
  }

}
