#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mini, tmp;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        mini = i;
        for (int j = i; j < n; j++) {
            if(a[j] < a[mini]){
                mini = j;
            }
        }
        tmp = a[i];
        a[i] = a[mini];
        a[mini] = tmp;
        if(i !=  mini){
            cnt++;
        }
    }

    for (int i = 0; i < n-1; i++) {
        cout << a[i] << " ";
    }

    cout << a[n-1] << endl;
    cout << cnt << endl;


    return 0;
}
