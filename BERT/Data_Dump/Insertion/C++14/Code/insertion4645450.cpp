#include<iostream>
using namespace std;
int main(){
  int n,A[100],j,v;
  cin>>n;
  for(int i = 0; i<n ; i++){
      cin>>A[i];
  }
  for(int i = 0; i<n; i++){
      v = A[i];
      j = i-1;
      while(j>=0&&A[j]>v){
          A[j+1]=A[j];
          j--;
      }
          A[j+1]=v;
      for(int k = 0; k<n-1; k++){
          cout << A[k] << " ";
      }
      cout << A[n-1] << endl;
  }
  return 0;
}
