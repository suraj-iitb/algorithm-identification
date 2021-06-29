/*
for i = 1 to A.length-1
    key = A[i]
    j = i - 1
    while j >= 0 and A[j] > key
        A[j+1] = A[j]
        j--
    A[j+1] = key
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
        cin>>v[i];
    for(j=0;j<v.size();j++){
        cout<<v[j]<<((j!=v.size()-1)?' ':'\n');
    }
    for(i=1;i<n;i++){
        int k=v[i];
        j=i-1;
        while(j>=0&&v[j]>k){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=k;
        for(j=0;j<v.size();j++){
            cout<<v[j]<<((j!=v.size()-1)?' ':'\n');
        }
    }
}
