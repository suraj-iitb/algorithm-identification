#include <iostream>

using namespace std;

void print_table(int A[], int n){
  for(int i=0;i<n;i++){
    if(i)cout<<' ';
    cout<<A[i];
  }
  cout<<endl;
}
 
int main(){

  int n,key,A[100],j;
 
  cin>>n;
  for(int i=0;i<n;i++) cin>>A[i];
  print_table(A, n);
  for(int i=1;i<n;i++){
    key=A[i];
    j=i-1;
    while(j>=0&&A[j]>key){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=key;
    print_table(A, n);
  }
  return 0;
}
