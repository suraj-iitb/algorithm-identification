#include <iostream>
using namespace std;

int main() {
    int n; cin >>n;
    int a[105];
    for(int i=1;i<=n;i++) cin >>a[i];
    int ans = 0;
    for(int i=1;i<=n-1;i++) {
        int id = i;
        for(int j=i+1;j<=n;j++) {
            if(a[j]<a[id]) {
                id = j;
            }
        }
        if(id!=i) {
            swap(a[id],a[i]);
            ans++;
        }
    }
    for(int i=1;i<=n-1;i++) cout << a[i] << " ";
    cout << a[n] <<endl << ans << endl;
    return 0;
}

