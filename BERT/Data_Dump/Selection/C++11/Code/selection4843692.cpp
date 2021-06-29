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
   int minj;
   bool sw;
   int cnt=0;
   
   rep(i,N){
       minj=i;
       sw=false;
       for(int j=i;j<N;j++){
           if(A[j]<A[minj]){
               minj=j;
               sw=true;
           }
       }
        if(sw==true){
               cnt++;
           }
       swap(A[i],A[minj]);
       
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

