#include<iostream>
using namespace std;

int main(){
    int n, s = 0;
    cin >> n;
    int a[100] = {};
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int j = 0; j < n; j++){
        int minj = j;
        for(int k = j; k < n; k++){
            if (a[minj] > a[k]) minj = k;
        }
        swap(a[minj], a[j]);
        if (minj != j) s++; 
    }
    for(int i = 0; i < n; i++){
        cout << a[i];
        if (i != n-1) cout << " ";
    }
    cout << "\n";
    cout << s << endl;

    return 0;
}

