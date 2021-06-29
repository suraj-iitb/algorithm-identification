#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;


int main(){
   int N,A[100],mini;
   int sw =0;
   cin >> N;
   for(int i=0;i<N;i++)cin >> A[i];
   for(int i=0;i<N; i++){
      mini=i;
      for(int j=i;j<N;j++){
          if(A[mini]>A[j]) mini=j; 
      } 
      swap(A[i],A[mini]);
      if(mini != i)sw++;
   }
    for(int i=0;i<N;i++){
        if(i>0)cout << " ";
        cout << A[i] ;
    }
    cout << endl;
    cout << sw << endl;
    

   return 0;

}

