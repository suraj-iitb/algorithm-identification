#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,a;
    std::deque<int> deq;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a;
        deq.emplace_back(a);
    }
    int count = 0;
    int flag = 1;
    while (flag==1) {
        flag = 0;
        for (int j=n-1;0<j;j--) {
        if (deq[j]<deq[j-1]) {
            int tmp = deq[j];
            deq[j] = deq[j-1];
            deq[j-1] = tmp;
            count++;
            flag = 1;
        }
    }
    }
    for (int k=0;k<deq.size();k++) {
        if (k==deq.size()-1) {
            cout << deq[k] << endl;
        } else {
            cout << deq[k] << " ";
        }
    }
    cout << count << endl;
}

