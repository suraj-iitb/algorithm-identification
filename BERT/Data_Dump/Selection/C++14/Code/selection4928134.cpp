#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 0; i < n ;i++){
        int minj = i;
        for(int j = i; j < n; j++){
            if(a[j] < a[minj]){
                minj = j;
            }
        }
        int tmp;
        tmp = a[i];
        a[i] = a[minj];
        a[minj] = tmp;
        if(i != minj){
            cnt++;
        }
    }
    for(int i = 0; i < n-1; i++){
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
    cout << cnt << endl;
    
    return 0;
}
