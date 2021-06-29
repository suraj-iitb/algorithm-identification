#include    <bits/stdc++.h>
using   namespace   std;

int main() {
    int N;
    cin >>N;
    vector<int> A(N, 0);
    for (int i=0; i<N; i++)
        cin >>A.at(i);
    int S=0;
    for (int i=0; i<N-1; i++)
        for (int j=N-1; j>i; j--)
            if (A.at(j)<A.at(j-1)) {
                S++;
                swap(A.at(j), A.at(j-1));
            }
    for (int i=0; i<N-1; i++)
        cout <<A.at(i) <<' ';
    cout <<A.back() <<endl;
    cout <<S <<endl;
    return 0;
}
