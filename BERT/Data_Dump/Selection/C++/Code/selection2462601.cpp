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
    for(int i=0;i<n;i++){
        int minj=i;
        for(int j=i;j<n;j++){
            if(a[j]<a[minj]){
                minj=j;
            }
        }
        if(minj!=i){
            int t=a[i];
            a[i]=a[minj];
            a[minj]=t;
            cnt++;
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
