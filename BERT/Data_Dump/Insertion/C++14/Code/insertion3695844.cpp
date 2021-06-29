#include <bits/stdc++.h>
using namespace std;

void vecout(vector<int>A){
for(int i=0 ; i<A.size() ;i++){
if(i) cout<< " " ; cout << A[i]; }
cout << endl;}

int main(){
int n,v,j; cin>>n;
  vector<int>vec(n);
  for(int i=0;i<n;i++) cin>>vec[i];
   vecout(vec);
  for(int i=1 ; i<n ;i++){
v=vec[i];
    j=i-1;
    while(j>=0&&vec[j]>v){
    vec[j+1]=vec[j];
      j--;
    }
    vec[j+1]=v;    
 vecout(vec);
}
}
