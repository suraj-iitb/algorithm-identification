using namespace std;
#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(int)(N);i++)


void printAll(int a[],int N){
  rep(i,N-1) printf("%d ",a[i]);
  cout << a[N-1] << endl;
}

void selectionSort(int A[],int N,int& cnt){
  for(int i=0;i<N;i++){
    int min_j = i;

    for(int j=i;j<N;j++){
      if(A[j] < A[min_j])swap(min_j,j);
    }

    if(i != min_j){
      swap(A[i],A[min_j]);
      cnt++;
    }
    //printAll(A,N);
  }
}

int main(){
  int N;
  cin >> N;
  int a[N];
  rep(i,N)cin >> a[i];

  int cnt = 0;
  selectionSort(a,N,cnt);
  
  printAll(a,N);
  cout << cnt << endl;
}
