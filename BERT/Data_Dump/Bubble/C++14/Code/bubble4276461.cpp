#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int cnt = 0;
    bool flag = 1;
    while(flag){
        flag = 0;
        for(int j = n-1; j > 0; j--){
            if(a[j] < a[j-1]){
                swap(a[j], a[j-1]);
                flag = 1;
                cnt++;
            }
        }
    }
    for(int k = 0; k < n; k++)
        cout << a[k] << (k == n-1 ? '\n' : ' ');
    cout << cnt << endl;
    return 0;
}
