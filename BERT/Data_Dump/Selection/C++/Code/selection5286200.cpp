#include <iostream>
using namespace std;

int n;
long long a[101], mini, s;
bool d;

int main() {
    cin >> n;
    for(int i = 0; i <= n-1; i++) {
        cin >> a[i];
    }
    for(int i = 0; i <= n-1; i++) {
        mini = i;
        for(int j = i; j <= n-1; j++) {
            if(a[j] < a[mini]) {
                mini = j;
            }
        }
        if(mini != i) {
            s++;
        }
        swap(a[i], a[mini]);
    }
    for(int i = 0; i < n-1; i++) {
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
    cout << s << endl;
}
