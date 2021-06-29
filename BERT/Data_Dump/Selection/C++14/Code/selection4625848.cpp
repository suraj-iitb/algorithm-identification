#include <iostream>
using namespace std;
int main(){
    int n, cnt = 0; cin >> n;
    int a[n]; for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i){
        int minj = i;
        for(int j = i; j < n; ++j){
            if(a[j] < a[minj]){
                minj = j;
            }
        }
        if(minj != i){
            swap(a[minj], a[i]);
            cnt++;
        }
    }
    for(int i =  0; i < n;++i){
        if(i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
