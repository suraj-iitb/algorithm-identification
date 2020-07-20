#include <iostream>

using namespace std;

//bubble sort


int main() {

    int n, tmp;
    int a[100];
    int count = 0;
    int flag = 1;

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];

    }


    while (flag) {
        flag = 0;
        for (int j=n-1; j>=1; j--){
            if (a[j] < a[j-1]) {
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                flag = 1;
                count++;
            }
        }
    }

    for(int i=0; i<n; i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << count << endl;

    return 0;
}
