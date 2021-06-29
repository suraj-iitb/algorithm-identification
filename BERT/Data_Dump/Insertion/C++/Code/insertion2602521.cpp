#include<iostream>
#include<vector>
using namespace std;
int main() { 
    int n;
    while (cin>>n) {
        vector<int> cnt;
        int x;
        while (n--) {
            cin>>x;
            cnt.push_back(x);
        }
        for (int i = 0 ; i < cnt.size(); i++) {
            int tmp = cnt[i];
            for (int j = i-1; j >=0; j--) {
                if (tmp < cnt[j]) cnt[j+1] = cnt[j];
                else {
                    cnt[j+1] = tmp;
                    break;
                } 
            }
            if (tmp < cnt[0]) cnt[0] = tmp;
            cout<<cnt[0];
            for (int k = 1; k < cnt.size(); k++) {
                cout<<" "<<cnt[k];
            }
            cout<<endl;
        }

    }
}
