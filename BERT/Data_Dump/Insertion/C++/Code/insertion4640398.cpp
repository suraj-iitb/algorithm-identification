#include <bits/stdc++.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
static const int MAX=200000;

int main(){
int n;
cin>>n;
vector<int> vec(n);
for (int i = 0; i < n; i++) {
  cin >> vec.at(i);
}
for(int j=0;j<n;j++) cout << vec[j] << (j==n-1?'\n':' ');
for(int i=1;i<n;i++){
    int v;
    v=vec[i];
    int j;
    j=i-1;
    while(j>=0&&vec[j]>v){
        vec[j+1]=vec[j];
        j--;
    }
    vec[j+1]=v;
    for(j=0;j<n;j++) cout << vec[j] << (j==n-1?'\n':' ');
}

return 0;
}

