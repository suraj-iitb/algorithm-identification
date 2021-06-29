#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,cnt=0;
    cin >> n;
    int a[n];
    bool flag=1;
    for(int i=0;i<n;i++) cin >> a[i];
    while(flag){
        flag=0;
        for(int i=n-1;0<i;i--){
            if(a[i]<a[i-1]){
                int b=a[i];
                a[i]=a[i-1];
                a[i-1]=b;
                cnt++;
                flag=1;
                }
        }
    }
    for(int i=0;i<n-1;i++) cout << a[i] << " ";
    cout << a[n-1] << endl;
    cout << cnt << endl;
}
