#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    bool flag = 1;
    int cnt = 0;
    int tmp;
    while(flag){
        flag = 0;
        for(int j=n-1; j>0; j--){
            if(a[j] < a[j-1]){
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                cnt++;
                flag = 1;
            }
        }
    }

    for(int k=0; k<n; k++) {
        if(k != n-1){
            cout << a[k] << " ";
        }else{
            cout << a[k] << endl;
        }
    }
    cout << cnt << endl;
    
    return 0;
}
