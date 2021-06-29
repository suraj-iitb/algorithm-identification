#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,a,count;
    count = 0;
    std::deque<int> deq;
    cin >> n;
    for (int r=0;r<n;r++) {
        cin >> a;
        deq.emplace_back(a);
    }
    
    for (int i=0;i<=n-1;i++) {
        int min = i;
        for (int j=i;j<=n-1;j++) {
            if (deq[min]>deq[j]) {
                min = j;
            }
        }
        if (min!=i) {
            int tmp = deq[min];
            deq[min] = deq[i];
            deq[i] = tmp;
            count++;
        }
    }
    for (int h=0;h<deq.size();h++) {
        if (h==deq.size()-1) {
            cout << deq[h] << endl;
        } else {
            cout << deq[h] << " ";
        }
    }
    cout << count << endl;
}
