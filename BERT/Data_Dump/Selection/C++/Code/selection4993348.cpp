#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[100] = {0};
    for (int i = 0; i < n; i++) cin >> a[i];

    int min = 10000000, index = 0, count = 0;
    for (int i = 0; i < n; i++){
        index = i;
        min = a[index];
        for (int j = i + 1; j < n; j++){
            if (a[j] < min){
                min = a[j];
                index = j;
            }
        }
        
        a[index] = a[i];
        a[i] = min;
        if (index != i) count++;
    }
    for (int i = 0; i < n; i++) cout << a[i] << (i == n - 1 ? "\n" : " ");
    cout << count << endl;
    return 0;
}
