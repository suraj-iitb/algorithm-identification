#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cnt = 0;

    bool frag = true;
    while(frag){
        frag = false;
        for(int j = n-1; j > 0; j--){
            if(a[j] < a[j-1]){
                int tmp;
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                cnt++;
                frag = true;
            }
        }
    }
    for(int i = 0; i < n-1; i++){
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
    cout << cnt << endl;
    return 0;
}

