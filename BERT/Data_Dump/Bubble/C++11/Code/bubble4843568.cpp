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
   int flag=1;
   int cnt=0;
   int i=0;
   while(flag){
       flag=0;
       for(int j=N-1;j>=i+1;j--){
           if(A[j]<A[j-1]){
               swap(A[j],A[j-1]);
               cnt++;
               flag=1;
           }
           
       }
       i++;
   }
   rep(i,N){
       if(i>0){
           cout<<" ";
       }
       cout<<A[i];
   }
   cout<<endl;
   cout<<cnt<<endl;
    
}

