#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
 
int main(){
 
int A[100];
 int N ,v,i;// N 個の要素を含む 0-オリジンの配列 A
 int count = 0;
 bool flag = 1;
 cin >> N;
for(int k = 0; k < N; k++){
  cin >> A[k];
}
   while( flag){
     flag = 0;
     for (int j=N-1; j > 0; j--){
     
       i = j-1;//i<j
       
       if (A[j] < A[i]){
         swap(A[j] , A[i]);
         
         count++;
         flag = 1;
       }//if
       
     i--;
     }//for

   }//while
   
    for(int i = 0; i < N; i++){
    if(i == N-1){
      cout << A[i];
      }else{
        cout << A[i] << " ";
      }
    }cout << endl;
    cout << count << endl;
    
return 0;
}
