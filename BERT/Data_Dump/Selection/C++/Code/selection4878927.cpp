#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int ans = 0;
    
    for (int i = 0; i < n; i++){
        int min_Num = 101;
        int sort_Posi = i;
        for (int j = i; j < n; j++){
            if (min_Num > a[j]){
                min_Num = a[j];
                sort_Posi = j;
            }
        }
        if (a[i] > a[sort_Posi]){
            swap(a[i], a[sort_Posi]);
            ans++;
        }
    }
    for (int i = 0; i < n; i++){
        if (i != 0){
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
    cout << ans << endl;
}

