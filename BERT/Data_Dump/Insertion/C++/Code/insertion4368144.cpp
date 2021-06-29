#include<bits/stdc++.h>
#define lol long long
using namespace std;
signed main(){
    int a[1010];
    int n;
    cin >>n;
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    cout <<a[0];
    for(int i=1;i<n;i++){
        cout <<' '<<a[i];
    }
    cout <<'\n';
    for(int i=1;i<n;i++){
        int v=a[i];
        int j=i-1;
        while(j>=0&&a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        cout <<a[0];
        for(int k=1;k<n;k++){
            cout <<' '<<a[k];
        }
        cout <<'\n';
    }
}
