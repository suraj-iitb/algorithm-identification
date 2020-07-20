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
    
   int n,flag=1,t,ans=0;
   cin>>n;
   
   vector<int> a(n);
   rep(i,n)cin>>a.at(i);
   
   while(flag){
      
       flag=0;
       for(int j=n-1;j>0;j--){
           
           if(a.at(j)<a.at(j-1)){
                ans++;
               t=a.at(j);
               a.at(j)=a.at(j-1);
               a.at(j-1)=t;
               flag=1;
           }
       }
   }
   rep(i,n-1)cout<<a.at(i)<<" ";
   cout<<a.at(n-1)<<endl;
   cout<<ans<<endl;
}
  

