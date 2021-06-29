#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;


int main(){
   int N,A[100];
   bool flag =1;
   int sw =0;
   cin >> N;
   for(int i=0;i<N;i++)cin >> A[i];
   for(int i=0;flag;i++){
       flag=0;
       for(int j=N-1;j>=i+1;j--){
           if(A[j]<A[j-1]){
               swap(A[j],A[j-1]);
               flag=1;
               sw++;
           }
       }
    }
    for(int i=0;i<N;i++){
        if(i>0)cout << " ";
        cout << A[i] ;
    }
    cout << endl;
    cout << sw << endl;
    

   return 0;

}

