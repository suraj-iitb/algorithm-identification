#include <iostream>
using namespace std;

int main(){
    int n,cnt;
    int a[100];
    bool flag = true;
    cin >> n;
    cnt = 0;
    for(int i=0; i<n; i++) cin >> a[i];
    while(flag){
        flag = false;
        for(int j=n-1; j>0; j--){
            if(a[j] < a[j-1]){
                swap(a[j],a[j-1]);
                cnt += 1;
                flag = true;
            };
        };
    };
    for(int i=0; i<n-1; i++){
        cout << a[i] << " ";
    };
    cout << a[n-1] << endl << cnt << endl;
    return 0;
}