#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int flag=1,j=0,c=0;
    while(flag){
        flag=0;
        for(int i=n-1;i>0;i--){
            if(a[i]<a[i-1]){
                swap(a[i],a[i-1]);
                c++;
                flag=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" \n"[i==n-1];
    }
    cout<<c<<endl;
    return 0;
}
