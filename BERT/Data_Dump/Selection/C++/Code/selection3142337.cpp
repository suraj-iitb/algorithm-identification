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
    int cnt=0;

    for(int i=0;i<N-1;i++){
        int minj = i;
        for(int j=i;j<N;j++){
            if(a[j] < a[minj]) minj = j;
        }
        swap(a[i], a[minj]);
        if(i != minj) cnt++;
    }
    

    for(int i=0;i<N-1;i++) cout << a[i] << ' ';
    cout << a[N-1] << endl;
    cout << cnt << endl;
}
