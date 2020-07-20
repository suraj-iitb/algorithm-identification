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
bool flag=1;
for (int i=0;flag;i++){
    flag=0;
    for(int j=n-1;j>=i+1;j--){
        if(vec[j]<vec[j-1]){
            swap(vec[j],vec[j-1]);
            flag=1;
            sw++;
        }
    }
}
for(int i=0;i<n;i++){
    if(i)cout<<" ";
    cout<<vec[i];
}
cout<<endl;
cout<<sw<<endl;
return 0;
}
