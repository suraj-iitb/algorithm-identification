#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    int minj = 0;
    int tmp;
    int cnt = 0;
    for(int i=0; i<n; i++){
        minj = i;
        for(int j=i; j<n; j++){
            if(a[j] < a[minj]){
                minj = j;
            }
        }
        if(minj != i){
            cnt++;
            tmp = a[i];
            a[i] = a[minj];
            a[minj] = tmp;
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

