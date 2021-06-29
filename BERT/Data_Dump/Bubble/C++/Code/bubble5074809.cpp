#include<iostream>

using namespace std;

const int MAX = 100000;
int count =0;
int array[MAX];
//void InsertionSort(int A[], int N);
void bubbleSort(int A[], int N);

int main(){
  int N;
  cin >> N;
  for(int i = 0; i < N;i++){
    cin >> array[i];
  }

  bubbleSort(array,N);
  for(int i = 0; i < N;i++){
    if(i < N-1)
    cout << array[i] <<" ";
    else
    cout << array[i] << endl;
  }

cout << count << endl;

return 0;
}

void bubbleSort(int A[], int N){
  bool flag = true;
  while(flag){
    flag = false;
    for(int i = 0 ; i < N;i++)
    {
      if(A[i]<A[i-1])
        {
          int a = A[i];
          A[i] = A[i-1];
          A[i-1] = a;
          flag = true;
          count++;
        }
    }
  }

}
