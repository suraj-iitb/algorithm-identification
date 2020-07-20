#include <iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    int n; cin >> n; int r[200000]; int m = 0; bool y = false;
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    for (;;) {
        if (n != 1) {
            for (int i = 0; i < n - 1; i++) {
                if (r[i] > r[i + 1]) {
                    swap(r[i], r[i + 1]);
                    ++m;
                    break;
                }
                if (i == n - 2 || n - 1 == 0) {
                    y = true;
                    break;
                }
            }
            if (y)
                break;
        }
        else
            break;
    }
    for (int i = 0; i < n - 1; i++) {
        cout << r[i] << " ";
    }
    cout  << r[n - 1]<< endl;
    cout << m << endl;
}
