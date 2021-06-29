#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    bool nsort=true;
    int sc=0;
    while (nsort){
        nsort=false;
        for (int i = 0; i < n-1; ++i) {
            if(a[i]>a[i+1]){
                int t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
                nsort=true;
                ++sc;
            }
        }
    }
    for (int i = 0; i < n-1; ++i) {
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<endl;
    cout<<sc<<endl;
    return 0;
}
