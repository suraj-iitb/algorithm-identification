#include<iostream>
using namespace std;
int main(){
    int n, ans =0;
    cin >> n;
    int a[n];
    bool flag = true;
    for(int i = 0; i< n; i++){
        cin >> a[i];
    }
    while(flag){
        flag = false;
        for(int i = 0; i<n-1; i++){
            if(a[i] > a[i+1]){
                int temp = a[i+1];
                a[i+1] = a[i];
                a[i] = temp;
                ans += 1;
                flag = true;
            }
        }
    }
    for(int i = 0; i< n-1; i++){
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl << ans << endl;
    return 0;
}
