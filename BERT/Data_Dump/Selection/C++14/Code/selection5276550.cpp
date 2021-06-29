#include <bits/stdc++.h>
using namespace std;

int main(){
    //入力
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    //処理
    int counter = 0;
    for(int i=0; i<n; i++){
        int minj  = i;
        for(int j=i; j<n; j++){
            if(a[j]<a[minj]) minj = j;
        }
        if(minj!=i){
            int tmp = a[i];
            a[i] = a[minj];
            a[minj] = tmp;
            counter++;
        }
    }

    //出力
    for(int i=0; i<n; i++){
        if(i<n-1) cout << a[i] << " ";
        else cout << a[i] << endl;
    }
    cout << counter << endl;
    
    return 0;
}
