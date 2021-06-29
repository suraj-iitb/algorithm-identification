#include<iostream>
using namespace std;

int main(){
 int n;
 cin >> n;

 int* A = new int[n];
 for(int i=0;i<n;i++){
   cin >> A[i]; 
 }

 for(int i=0;i<n;i++){
   int v = A[i],j= i-1;
   while(j>=0 && A[j] > v){
     A[j+1] = A[j];
     j--;
   }
   A[j+1] = v;
   for(int k=0;k<n;k++){
     cout << (k != 0 ? " ": "") << A[k];
   }
   cout << endl;
 }
}
