#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int a[N];
    for(int i=0;i<N;i++) cin >> a[i];

    for(int i=0;i<N-1;i++) cout << a[i] << ' ';
    cout << a[N-1] << endl;

    for(int i=1;i<N;i++){
        int v = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        for(int k=0;k<N-1;k++) cout << a[k] << ' ';
        cout << a[N-1] << endl;
    }
}
