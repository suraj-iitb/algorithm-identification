#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int a[105];
    for(int i=1;i<=n;i++) cin >> a[i];
    int ans = 0;
    for(int i=1;i<=n-1;i++) {
        int tag = 0;
        for(int j=1;j<=n-i;j++) {
            if(a[j] > a[j+1]) {
                swap(a[j],a[j+1]);
                tag = 1;
                ans++;
            }
        }
        if(tag == 0) break;
    }
    cout << a[1] ;
    for(int i=2;i<=n;i++) cout << " " << a[i];
    cout << endl << ans <<endl;
    return 0;
}

