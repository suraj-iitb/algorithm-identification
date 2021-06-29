#include    <bits/stdc++.h>
using   namespace   std;

int main() {
    int N;
    cin >>N;
    vector<int> A(N, 0);
    for (int i=0; i<N; i++)
        cin >>A.at(i);
    int S=0;
    for (int i=0; i<N; i++) {
        int MINI=i;
        for (int j=i; j<N; j++)
            if (A.at(j)<A.at(MINI))
                MINI=j;
        if (i!=MINI) {
            S++;
            swap(A.at(i), A.at(MINI));
        }
    }
    for (int i=0; i<N-1; i++)
        cout <<A.at(i) <<' ';
    cout <<A.back() <<endl;
    cout <<S <<endl;
    return 0;
}
