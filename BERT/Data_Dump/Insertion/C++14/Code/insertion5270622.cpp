#include <bits/stdc++.h>
using namespace std;

// void insertionSort(vector<int> &a){
//     int n = a.size();
//     for(int i=1; i<n; i++){
//         int v = a[i];
//         int j = i-1;
//         while(v<a[j] && j>=0){
//             a[j+1] = a[j];
//             j--;
//         }
//         a[j+1] = v;
//     }
// }

int main(){
    //入力
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i]; 

    //処理
    for(int i=1; i<n; i++){
        for(int x=0; x<n; x++){
            if(x!=n-1) cout << a[x] << " ";
            else cout << a[x];
        }
        cout << endl;
        int v = a[i];
        int j = i-1;
        while(v<a[j] && j>=0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;

    }

    //出力
    for(int x=0; x<n; x++){
        if(x!=n-1) cout << a[x] << " ";
        else cout << a[x];
    }
    cout << endl;

    return 0;
}
