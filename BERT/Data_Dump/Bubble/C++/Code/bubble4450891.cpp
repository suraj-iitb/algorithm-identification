#include<iostream>
using namespace std;
static const int MAX = 100;

void trace(int A[], int n){
  for(int i=0; i<n; i++ ){
    if(i>0)cout<<' ';
    cout<<A[i];
  }
  cout<<endl;   
}

int bubbleSort(int A[],int N){
  bool flag = true;
  int times = 0;
  for (int i=0; flag; i++ ){
    flag=false;
    for(int j=N-1; j>=i+1; j--){
      if(A[j] < A[j-1]){
        int tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
        flag = true;
        times++;
      }
    }
  }
  trace(A,N);
  return times;
}

int main(){
  int n, a[MAX], times;

  cin >> n;

  for( int i=0; i<n; i++ ) cin >> a[i];

  times = bubbleSort(a,n);
  cout << times << endl;

  return 0;
}
