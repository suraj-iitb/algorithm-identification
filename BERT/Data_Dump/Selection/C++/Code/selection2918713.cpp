//
// Created by yoshihito.hotta on 2018/06/10.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    int *a;
    cin >> n;
    a = new int [n];

    for (int i = 0; i < n ; i++) cin >> a[i];

    int sw = 0;
    for (int i = 0; i < n; i++) {
        int jmin = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[jmin]) jmin = j;
        }
        swap(a[jmin], a[i]) ;
        if(jmin != i) sw ++ ;
    }
    for (int i = 0; i < n; i++) {
        if(i) cout << " ";
        cout << a[i];
    }
    cout << endl << sw << endl;

    return 0;
}


