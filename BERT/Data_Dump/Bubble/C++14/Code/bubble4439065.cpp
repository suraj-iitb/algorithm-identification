#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <set>
#include <list>

using namespace std;


int main() {
    int n, flag{1}, count{0};
    cin >> n;
    int A[n];
    for(int i=0; i<n;i++){
        cin >> A[i];
    }

    while (flag) {
        flag = 0;
        for (int i = n - 1; i > 0; i--) {
            if (A[i] < A[i - 1]) {
                swap(A[i], A[i - 1]);
                flag = 1;
                count++;
            }
        }
    }

    for(int i=0; i<n;i++){
        cout << A[i];
        if (i==n-1) cout << endl;
        else cout << " ";
    }
    cout << count << endl;
}
