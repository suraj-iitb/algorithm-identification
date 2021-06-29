#include<iostream>
#include <limits.h>
#include<string>
using namespace std;

int main(){
    int n = 0;
    cin >> n;

    int R[100]; 
    for(int i = 0; i < n; i++) cin >> R[i];

    int v = 0;

    for(int j = 1 ; j < n; j++) {

        for(int h = 0; h < n; h++) {
            if(h > 0) cout << " ";
            cout << R[h];
        }
        cout << endl;

        v = R[j];
        int k = j - 1;

        while(k >= 0 && R[k] > v) {
            R[k+1] = R[k];
            k--;
        }

        R[k+1] = v;
    }

    for(int h = 0; h < n; h++) {
        if(h > 0) cout << " ";
        cout << R[h];
    }
    cout << endl;

    return 0;
}

