#include    <bits/stdc++.h>
using   namespace   std;

#define MAX_A   10000

int main() {
    int n;
    cin >>n;
    vector<int> C(MAX_A+1, 0);
    vector<int> A(n, 0);
    for (int i=0; i<n; i++) {
        cin >>A.at(i);
        C.at(A.at(i))++;
    }
    for (int i=1; i<=MAX_A; i++)
        C.at(i) +=C.at(i-1);
    vector<int> B(n+1, 0);
    for (int i=0; i<n; i++) {
        B.at(C.at(A.at(i)))=A.at(i);
        C.at(A.at(i))--;
    }
    for (int i=1; i<=n; i++)
        if (i==1)
            cout <<B.at(i);
        else
            cout <<' ' <<B.at(i);
    cout <<endl;
    return 0;
}
