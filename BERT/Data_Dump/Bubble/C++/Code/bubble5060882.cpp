#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a[100],cnt=0,flg;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    while(1){
        flg=0;
        for(int i=n-1;i>0;i--){
            if(a[i]<a[i-1]){
                cnt++;
                swap(a[i],a[i-1]);
                flg=1;
            }
        }
        if(flg==0){
            break;
        }
    }
    for(int i=0;i<n;i++){
        cout << a[i];
        if(i!=n-1){
            cout << ' ';
        }
    }
    cout << endl;
    cout << cnt << endl;
}
