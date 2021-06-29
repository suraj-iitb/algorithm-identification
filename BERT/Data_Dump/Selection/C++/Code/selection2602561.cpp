#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int n, x;
    while (cin>>n) {
        int counts = 0;
        vector<int> cnt;
        while (n--) {
            cin >> x;
            cnt.push_back(x);
        }
        for (int i = 0; i < cnt.size(); i++) {
            int key = i;
            for (int j = i; j < cnt.size(); j++) {
                if (cnt[j] < cnt[key]) {
                    key = j;                   
                }
            }
            if (key != i) {
                counts++;int a = cnt[key];cnt[key] = cnt[i];cnt[i] = a;
            }
            
        }
        cout<<cnt[0];
        for (int i = 1; i < cnt.size(); i++) cout<<" "<<cnt[i];
        cout<<endl<<counts<<endl;
    }
    return 0;
}
