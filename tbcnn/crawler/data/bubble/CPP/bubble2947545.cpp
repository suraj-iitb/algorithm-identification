#include<iostream>
using namespace std;

int bubbleSort(int X[], int Y){
  int cn = 0;
  bool num =1;
  int i,j;

  for(i=0;num; i++){
    num =0;
    for(j=Y-1;j>=i+1;j--){
      if(X[j]<X[j-1]){
	swap(X[j],X[j-1]);
	num = 1;
	cn++;
      }
    }
  }
  return cn;
}

int main(){
  int deta[100],N,cn;
  int i;
  cin >> N;

  for(i=0;i<N;i++){
    cin >> deta[i];
  }
  cn = bubbleSort(deta,N);


  for(i=0;i<N;i++){
    if(i) {
      cout<<" ";
    }
    cout << deta[i];
  }
    cout << endl;
    cout << cn <<endl;

    return 0;
  }

