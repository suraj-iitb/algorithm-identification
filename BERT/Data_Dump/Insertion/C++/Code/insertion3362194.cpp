#include <iostream>
#define N 100

using namespace std;

int A[N], n;

void print(){
  int i;
  for(i = 0;i < n;i++){
      cout << A[i];
      if(i != n - 1)
	cout << " ";
    }
    cout << endl;
}

void insertionSort(){
  int i, j, key;
  for(j = 1;j < n;j++){
    key = A[j];
    i = j - 1;
    while(i >= 0 && A[i] > key){
      A[i+1] = A[i];
      i = i - 1;
    }
    A[i+1] = key;
    print();
  }
}

int main(){
  int i, j;
    
  cin >> n;
  for(i = 0;i < n;i++){
    cin >> A[i];
  }
  for(i = 0;i < n;i++){
    cout << A[i];
    if(i != n - 1)
      cout << " ";
  }
  cout << endl;
  insertionSort();
  return 0;
}

