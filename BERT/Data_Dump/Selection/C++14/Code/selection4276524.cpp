#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int cnt = 0;
    for(int i = 0; i < n; i++){
        int minj = i;
        for(int j = i; j < n; j++)
            if(a[j] < a[minj]) minj = j;
        if(i == minj) continue;
        swap(a[i], a[minj]);
        cnt++;
    }

    for(int k = 0; k < n; k++)
        cout << a[k] << (k == n-1 ? '\n' : ' ');
    cout << cnt << endl;
    return 0;
}
