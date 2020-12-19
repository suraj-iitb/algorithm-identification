//min selection sort 
//change to min from the first index
#include<iostream>
using namespace std;

int main() {
    int n,a[100];
    int c = 0;
    int minj; //temporary min number store
    int tmp;
    
    cin >> n;
    for ( int i = 0; i < n; i++ ) cin >> a[i];
    for ( int i = 0; i < n; i++ ) {
        minj = i;
        for ( int j = i; j < n; j++ ) {
            if ( a[j] < a[minj] ) {
                minj = j;
            }
        }
        if ( i != minj ) {
          tmp = a[i];
          a[i] = a[minj];
          a[minj] = tmp;
          c++;
        }
    }
    for ( int i = 0; i < n; i++ ) {
        cout << a[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;
    cout << c << endl;
}
