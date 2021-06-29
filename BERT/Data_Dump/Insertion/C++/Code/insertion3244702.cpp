#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void print_table(int A[],int n){
  for(int i=0;i<n;i++){
    cout << (i==0 ? "" : " ") << A[i];
  }
  cout << endl;
}

int main(){
  int buf1,n,v,A[100],j;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  print_table(A,n);

  for(int i=1;i<n;i++){
    v = A[i];
    j = i-1;
    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    print_table(A,n);
  }
}
