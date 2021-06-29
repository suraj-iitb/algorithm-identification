#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,count1=0;
    cin>>n;
    int i,j;
    vector<int> a(n);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int flag=1;
    while(flag){
        flag=0;
        for(j=n-1;j>=1;j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                count1++;
                flag=1;
            }
        }
    }
    for(i=0;i<n-1;i++){
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<endl;
    cout<<count1<<endl;
}
