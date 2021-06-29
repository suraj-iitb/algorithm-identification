//Deploy bubble-sort.
#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
vector<int> bubbleSort(vector<int> &a, int &c) {
   bool flag = true;
   while(flag) {
       flag = false;
       for(int i=a.size()-1; i>0; --i) {
           if(a[i] < a[i-1]) {
                int v = a[i];
                a[i] = a[i-1];
                a[i-1] = v;
                flag = true;
                c++;
           }
       }
   }
   return a;
}

int main() {
    int N;
    cin >> N;
    int count=0;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    bubbleSort(A, count);

    rep(i,N) {
        if(i == N-1) {
            cout << A[i] << endl;
        } else {
            cout << A[i] << " ";
        }
    }
    cout << count << endl;
    return 0;
}
