#include <iostream>
using namespace std;

int main(){
    int n, minj,cnt;
    int a[100];
    cin >> n;
    cnt = 0;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++){
        minj = i;
        for(int j=i; j<n; j++){
            if(a[j] < a[minj]) minj = j;
        };
        if(a[i] != a[minj]){
            swap(a[i],a[minj]);
            cnt += 1;
        };
    };
    for(int i=0; i<n-1; i++){
        cout << a[i] << " ";
    };
    cout << a[n-1] << endl << cnt << endl;
    return 0;
}
