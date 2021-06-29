#include <iostream>
using namespace std;

int main(){
    int n, a[100];
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> a[i];

    bool flag = true;

    int itr = 0;

    while(flag){
        flag = false;
        for (int j = n - 1; j > 0; --j){
            if (a[j] < a[j-1]){
                int tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                itr++;
                flag = true;
            }
        }
    }

    for (int i = 0; i < n - 1; ++i) cout << a[i] << " ";
    cout << a[n-1] << endl;
    cout << itr << endl;
}

