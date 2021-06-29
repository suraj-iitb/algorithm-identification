#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <set>
#include <cmath>

typedef long long ll;

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int flag = 1;
    int cnt = 0;
    while(flag){
        flag = 0;
        for(int i = n - 1; i >= 1; i--){
            if(a[i] < a[i - 1]){
                int b = a[i];
                a[i] = a[i - 1];
                a[i - 1] = b;
                flag = 1;
                cnt++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i];
        if(i == n - 1){
            cout << endl;
        } else {
            cout << " ";
        }
    }
    cout << cnt << endl;
}
