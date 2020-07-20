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

    bool flg = true;
    int cnt = 0;
    while(flg){
        flg = false;
        for(int i=N-1;i>0;i--){
            if(a[i] < a[i-1]){
                swap(a[i], a[i-1]);
                flg = true;
                cnt++;
            }
        }
    }
    

    for(int i=0;i<N-1;i++) cout << a[i] << ' ';
    cout << a[N-1] << endl;
    cout << cnt << endl;
}
