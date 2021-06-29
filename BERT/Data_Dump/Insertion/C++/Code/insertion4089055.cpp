#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int a[105];
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) {
        int tmp = a[i];
        int j = i;
        for( ;j>=2 && a[j-1]>=tmp;j--)
            a[j] = a[j-1];
        a[j] = tmp;
        for(int k=1;k<n;k++) cout << a[k] << " ";
        cout << a[n] <<endl;
    }
    return 0;
}

