#include <iostream>
using namespace std;

int n,A[100],sw;
int BubbleSort(int A[],int N){
     int sw = 0;
     bool flag = 1;
    for(int i = 0; flag; i++){
         flag = 0;
       for(int j = N-1;j >= i+1;j--){
           if(A[j] < A[j-1]){
             swap(A[j],A[j-1]);
             flag = 1;
             sw++;
           }
       }
    }
  return sw;
}

int main(){
  cin >> n;  
  for(int i = 0;i < n;i++) cin >> A[i];
  
  sw = BubbleSort(A,n);
  
  for(int i = 0;i < n;i++){
     if(i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << sw << endl;
  
  return 0;
}
