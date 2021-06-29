#include <iostream>

using namespace std;
int main() {
    int n, a[100];
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    int x;
    int flag = 1;
    int count = 0;

    while (flag){
        flag = 0;
        for (int j=n-1; j>0; j--){
            if (a[j] < a[j - 1]) {
                x = a[j - 1];
                a[j-1] = a[j];
                a[j] = x;
                flag = 1;
                count ++;
            }
        }
    }

    for (int k=0; k<n-1; k++){
        cout << a[k] << " ";
    }
    cout << a[n-1] << endl;
    cout << count << endl;
}
