#include<iostream>
using namespace std;

int main(){
    int n;
    int a[100];
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 0;i < n-1;i++){
        for(int j = 0; j < n-1 ;j++){
            if(a[j] > a[j+1]){//a[j], a[j+1]をチェック
                int tmp;
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                cnt++;
            }
        }
    }

    for(int i = 0;i < n;i++){
        if(i > 0)cout << " ";
        cout << a[i];
    }cout << endl;

    cout << cnt << endl;
    return 0;

}
