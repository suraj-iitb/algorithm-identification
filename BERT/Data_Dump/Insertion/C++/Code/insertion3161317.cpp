//AOJ Insertion Sort
//20180929
//F_Naru

#include<iostream>
using namespace std;

int N;
int main(){
  cin >> N;
  int*  num = new int[N];
  for(int i=0; i<N; i++){
    cin >> num[i];
  }
  
  int v;
  int j;
  for(int i=0; i<N; i++){
    v = num[i];
    j = i - 1;
    while(j>=0 && num[j] > v){
      num[j+1] = num[j];
      j--;
    }
    num[j+1] = v;

    for(int i=0; i<N; i++) {
      cout << num[i];
      if(i<N-1) cout << " ";
    }
    cout << endl;
  }
  
  delete[] num;
}


