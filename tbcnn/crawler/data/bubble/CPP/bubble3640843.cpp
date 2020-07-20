#include<iostream>
using namespace std;

int main(){
    int n, j, count,flag,tmp;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    count = 0;
    j = 0;
    flag = 1;
    while (flag==1) {
        flag = 0;
        for (int i=n-1; j < i; i--) {
            if (a[i] < a[i-1]) {
                tmp = a[i];
                a[i] = a[i-1];
                a[i-1] = tmp;
                flag = 1;
                count++;
            } 
        }
        j++;
    }
    for (int i=0; i<n-1; i++) {
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
    cout << count << endl;
    return 0;
}
