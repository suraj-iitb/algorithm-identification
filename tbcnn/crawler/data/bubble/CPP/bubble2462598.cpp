#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int cnt=0;
    bool flag=true;
    while(flag){
        flag=false;
        for(int i=n-1;i>=1;i--){
            if(a[i]<a[i-1]){
                int t=a[i];
                a[i]=a[i-1];
                a[i-1]=t;
                cnt++;
                flag=true;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        cout << a[i];
        if(i!=n-1)cout << " ";
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
