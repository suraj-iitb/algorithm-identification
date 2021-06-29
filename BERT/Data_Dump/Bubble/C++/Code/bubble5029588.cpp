#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;

  int main(){
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i,n)cin >> a[i];

        int count = 0;
        bool flag = true;
        while(flag){
            flag  = false;
            rep(i,n - 1){
                if(a[i] > a[i + 1]){
                    int x = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = x;
                    flag = true;
                    count++;
                }
            }
        }
        rep(i,n){
            cout << a[i];
            if(i == n - 1)continue;
            cout << " ";
        }
        cout << endl;
        cout << count << endl;
        return 0;
  }
