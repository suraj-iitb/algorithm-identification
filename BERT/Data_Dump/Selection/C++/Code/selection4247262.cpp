#include <bits/stdc++.h>
#include <iostream>
//#include <vector>
#define ALL(l)  (l).begin(),(l).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll maxn = 1000000000;

//---------------------------------------------------------------------------------------------------
 

 
 
int main(){
    
   int n,t,ans=0,minj;
   cin>>n;
   
   vector<int> a(n);
   rep(i,n)cin>>a.at(i);
   
   rep(i,n){
       
       minj=i;
       for(int j=i;j<n;j++){
           if(a.at(j)<a.at(minj)){
               minj=j;
               //ans++;
               
           }
       }
           if(a.at(i)>a.at(minj)){
             t=a.at(i);
             a.at(i)=a.at(minj);
             a.at(minj)=t;
             ans++;
           }
       
   }
   
   rep(i,n-1)cout<<a.at(i)<<" ";
   cout<<a.at(n-1)<<endl;
   cout<<ans<<endl;
}
  


