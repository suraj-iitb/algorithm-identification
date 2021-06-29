#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> a, int n){
    for(int k = 0; k < n; k++)
        cout << a[k] << (k == n-1 ? '\n' : ' ');
    return;
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    print(a, n);
    for(int i = 1; i < n; i++){
        int v = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        print(a, n);
    }
    return 0;
}
