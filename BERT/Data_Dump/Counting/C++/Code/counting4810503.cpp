#include <bits/stdc++.h>
using namespace std;
const int MAX = 2000001;
const int VMAX = 10000;

signed main() {
    int n; cin >> n;
    vector<int> A(n+1,0), B(n+1,0),C(VMAX+1,0);
    for(int i = 1; i <= n; i++) {
        cin >> A.at(i);
        C.at(A.at(i))++;
    }

    for(int i = 1; i <= VMAX; i++) C.at(i) += C.at(i-1);

    for(int i = 1; i <= n; i++) {
        B.at(C.at(A.at(i))--) = A.at(i);
    }

    for(int k = 1; k <= n; k++) {
        if(k > 1) printf(" ");
        printf("%d", B.at(k));
    }

    printf("\n");

    return 0;
}


