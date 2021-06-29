#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll= long long;
using namespace std;
int main(void){
   int N;
   cin>>N;
   int A[N];
   rep(i,N){
       cin>>A[i];
       
   }
   
   
   rep(i,N){
       int v=A[i];
       int j=i-1;
       while(j>=0&&A[j]>v){
           A[j+1]=A[j];
           j--;
       }
       A[j+1]=v;
       rep(i,N){
           if(i>0){
               cout<<" ";
           }
           cout<<A[i];
           
       }
       cout<<endl;
   }
    
}

