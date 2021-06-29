#include <bits/stdc++.h>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main(){
int n;
cin>>n;
vector<int> vec(n);
for (int i = 0; i < n; i++) {
  cin >> vec.at(i);
}
int sw=0;
for (int i=0;i<n;i++){
    int minj=i;
    for (int j=minj+1;j<n;j++ ){
        if(vec[j]<vec[minj]){
            minj=j;
        }
    }
    if(i!=minj){
        sw++;
    }
    swap(vec[i],vec[minj]);
        
       
       
            
           
    
}
 for(int j=0;j<n;j++) cout << vec[j] << (j==n-1?'\n':' ');
 cout<<sw<<endl;

return 0;
}

