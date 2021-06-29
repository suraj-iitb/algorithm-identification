#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n,x;
    while (cin >> n) {
        vector<int> cnt;
        while (n--){
            cin>>x;
            cnt.push_back(x);
        }
        int counts = 0;
        int key = cnt.size() - 1;
        for (int i = 0; i < cnt.size(); i++) {
            int minv = cnt[cnt.size() - 1];
            for (int j = cnt.size()-2; j >= i; j--) {
                if (minv < cnt[j]) {
                    counts++;
                    cnt[j+1] = cnt[j];
                } else {
                    cnt[j+1] = minv;
                    minv = cnt[j];
                }
            }
            cnt[i] = minv;
        }
        cout<<cnt[0];
        for (int i = 1; i < cnt.size(); i++) {
            cout<<" "<<cnt[i];
        }
        cout<<endl;
        cout<<counts<<endl;
    }
    return 0;
}
