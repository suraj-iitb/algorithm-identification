#include    <bits/stdc++.h>
using   namespace   std;

void    Print(vector<int> &A) {
    for (int i=0; i<A.size()-1; i++)
        cout <<A.at(i) <<' ';
    cout <<A.back() <<endl;
    return;
}

void    Insert(vector<int> &A, int s, int t) {
    int L=lower_bound(A.begin()+s, A.begin()+t, A.at(t))-A.begin();
    for (int i=t-1; i>=L; i--)
        swap(A.at(i), A.at(i+1));
    return;
}

int main() {
    int N;
    cin >>N;
    vector<int> A(N, 0);
    for (int i=0; i<N; i++)
        cin >>A.at(i);
    Print(A);
    for (int i=1; i<N; i++) {
        Insert(A, 0, i);
        Print(A);
    }
    return 0;
}
