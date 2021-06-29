#include <bits/stdc++.h>
using namespace std;

#define REPp(i, m, n) for(int (i)=(m);(i)<(n);(i)++)
#define REPm(j, m, n) for(int (j)=(m);(j)>(n);(j)--)

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    REPp(i, 0, N) {
        cin >> A[i];
    }
    
    bool flag = 1;
    int count = 0;
    while(flag) {
        flag = 0;
        REPm(j, N - 1, 0) {
            if(A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                count++;
                flag = 1;
            }
        }
    }
    
    REPp(i, 0, N - 1) cout << A[i] << " ";
    cout << A[N - 1] << endl << count << endl;
}
