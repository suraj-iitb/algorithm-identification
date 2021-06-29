#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, a[10000], temp, k = 0;

    cin >> n;

    for(int i = 0; i < n; i++)cin >> a[i];

    for(int i = 0; i < n; i++)
        for(int j = n - 1; j > i; j--)
        if(a[j] < a[j -1]){
            temp = a[j  - 1];
            a[j - 1] = a[j];
            a[j] = temp;
            k++;
        }
    for(int i = 0; i < n; i++){
            cout << a[i];
            if(i == n - 1)break;
            cout << " ";
    }

    cout << endl;
    cout << k <<endl;
    return 0;
}
