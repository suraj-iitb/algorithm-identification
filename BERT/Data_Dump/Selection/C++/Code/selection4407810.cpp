#include <iostream>
using namespace std;

int main(){
    int n, a[100];
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> a[i];

    int itr = 0;

    for (int i = 0; i < n - 1; ++i){
        int minj = i;
        for (int j = i; j < n; ++j){
            if (a[j] < a[minj]) minj = j;
        }
        int tmp = a[i];
        a[i] = a[minj];
        a[minj] = tmp;
        if (i != minj) itr++;
        
    }

    for (int i = 0; i < n - 1; ++i) cout << a[i] << " ";
    cout << a[n-1] << endl;
    cout << itr << endl;
}

