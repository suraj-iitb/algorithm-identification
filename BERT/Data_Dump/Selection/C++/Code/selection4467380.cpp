#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,i,j,minj,count1=0;
    cin>>n;
    vector<int> a(n);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n-1;i++){
        minj=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[minj]){
                minj=j;
            }
        }
        if(minj!=i){
            swap(a[i],a[minj]);
            count1++;
        }
    }
    for(i=0;i<n-1;i++){
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<endl<<count1<<endl;
}
