#include <iostream>
using namespace std;
int main(){
    int n; cin >> n;
    int a[n]; for(int i = 0; i < n; ++i) cin >> a[i];
    bool flag = true;
    int cnt = 0;
    while(flag){
        flag = false;
        for(int j = n-1; j != 0; --j){
            if(a[j] < a[j-1]){
                cnt++;
                swap(a[j], a[j-1]);
                flag = true;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        if(i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
