#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    int sc=0;
    for (int i = 0; i < n; ++i) {
        int minj=i;
        for (int j = i+1; j < n; ++j) {
            if(a[minj]>a[j])minj=j;
        }
        if(i!=minj){
            int t=a[i];
            a[i]=a[minj];
            a[minj]=t;
            ++sc;
        }

    }
    for (int i = 0; i < n-1; ++i) {
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<endl;
    cout<<sc<<endl;
    return 0;
}
