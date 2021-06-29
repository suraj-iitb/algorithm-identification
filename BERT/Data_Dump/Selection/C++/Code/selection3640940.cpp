#include<iostream>
using namespace std;

int main(){
    int n, minj, count, tmp;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    count = 0;
    for(int i=0; i<n; i++) {
        minj = i;
        for(int j=i; j<n; j++ ){
            if (a[j] < a[minj]) {
                minj = j;
            }
        }
        if (minj != i) {
            count++;
            tmp = a[i];
            a[i] = a[minj];
            a[minj] = tmp;
         }
    }
    for (int i=0; i<n-1; i++) {
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
    cout << count << endl;
    return 0;
}
