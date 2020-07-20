#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[200], n, count;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }

    for(int i = 0; i < n - 1;i++){
        for(int j = n - 1; j > i; j--){
            if(a[j] < a[j - 1]){
                swap(a[j],a[j-1]);
                count++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(i != n-1)
            cout << a[i] << " ";
        else
            cout << a[i] << endl;
    }

    cout << count << endl;

    return 0;
}
