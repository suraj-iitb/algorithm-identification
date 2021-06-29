#include<bits/stdc++.h>
using namespace std;

int n;
int a[2000001], b[2000001];

void CountingSort(int k){
    int c[10001] = {};

    for(int i = 1; i <= n; i++){
        c[a[i]]++;
    }

    for(int i = 1; i <= k ; i++){
        c[i] += c[i-1];
    }

    for(int j = n; j > 0; j--){
        b[c[a[j]]] = a[j];
        c[a[j]]--;
    }
}

int main(){
    int  maxl = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        maxl = max(a[i], maxl);
    }
    CountingSort(maxl);

    for(int i = 1; i <= n; i++){
        if(i != 1) cout << " ";
        cout << b[i];
    }
    cout << endl;
    return 0;
}
