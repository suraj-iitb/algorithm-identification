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
    int cnt  = 0;
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            int new_a = a[minIndex];
            a[minIndex] = a[i];
            a[i] = new_a;
            cnt++;
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
