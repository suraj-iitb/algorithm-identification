#include<bits/stdc++.h>                                                                                                                
using namespace std;
int a[120];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }   
    int flg = 1,tmp;
    int cnt = 0;
    while(flg){
        flg = 0;
        for(int i=1;i<n;++i){
            if(a[i] < a[i-1]){
                tmp = a[i];
                a[i] = a[i-1];
                a[i-1] = tmp;
                flg = 1;
                cnt++;
            }
        }
    }   
    for(int i=0;i<n;i++){
        if(i == 0)cout << a[i];
        else cout << ' ' << a[i];
    }   
    cout << '\n';
    cout << cnt << '\n';
    return 0;
}
