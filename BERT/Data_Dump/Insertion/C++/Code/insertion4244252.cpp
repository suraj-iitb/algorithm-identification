#include<iostream>
using namespace std;

int main(){
    int n, v, a[100];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        for(int k = 0; k < n-1; k++) cout << a[k] << ' ';
        cout << a[n-1] << endl;
        v = a[i];
        int j = i - 1;
        while((j >= 0) && (a[j] > v)){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
    for(int k = 0; k < n-1; k++) cout << a[k] << ' ';
    cout << a[n-1] << endl;
    return 0;
}