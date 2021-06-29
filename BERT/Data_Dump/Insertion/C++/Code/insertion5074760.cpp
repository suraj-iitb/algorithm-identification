#include<iostream>

using namespace std;

const int MAX = 100000;
int array[MAX];
void InsertionSort(int A[], int N);

int main(){
  int N;
  cin >> N;
  for(int i = 0; i < N;i++){
    cin >> array[i];
  }
  for(int i = 0; i < N;i++){
    if(i < N-1)
    cout << array[i] <<" ";
    else
    cout << array[i] << endl;
  }
    InsertionSort(array,N);


return 0;
}

void InsertionSort(int A[], int N){
  for(int i = 1; i < N; i++){
    int v = A[i];
    int j = i-1;

    while(j >= 0 && A[j] >v)
      {
        A[j+1] = A[j];
        j--;
      }
    A[j+1]=v;
    for(int i = 0; i < N;i++){
      if(i < N-1)
      cout << array[i] <<" ";
      else
      cout << array[i] << endl;
    }
  }

}

