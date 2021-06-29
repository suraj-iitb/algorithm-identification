#include<iostream>
using namespace std;
int main(){
    int n, cnt = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int flag = 1;
    while(flag){
        flag = 0;
        for(int j = n - 1; j > 0; j--){
            if(a[j] < a[j - 1]){
                swap(a[j], a[j - 1]);
                flag = 1;
                cnt++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(i == n - 1){
            cout << a[i] << endl;
        }else{
            cout << a[i] << " ";
        }
    }
    cout << cnt << endl;
    return 0;
}
