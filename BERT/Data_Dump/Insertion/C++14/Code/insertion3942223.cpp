#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,a;
    std::deque<int> deq;
    cin >> n;
    for (int x=0;x<n;x++) {
        cin >> a;
        deq.emplace_back(a);
    }
    for (int k=0;k<deq.size();k++) {
        if (k==deq.size()-1) {
            cout << deq[k] << endl;
        } else {
            cout << deq[k] << " ";
        }
    }
    for (int i=1;i<n;i++) {
        int v = deq[i];
        int j = i - 1;
        while (j>=0 && deq[j] > v) {
            deq[j+1] = deq[j];
            j--;
        }
        deq[j+1] = v;
        for (int l=0;l<deq.size();l++) {
        if (l==deq.size()-1) {
            cout << deq[l] << endl;
        } else {
            cout << deq[l] << " ";
        }
    }
    }
}

