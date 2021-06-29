#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    int n, a[100], count = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    bool flag = true;

    while(flag){
        flag = false;
        for(int i = n-1; i > 0; --i){
            if(a[i] < a[i-1]){
                swap(a[i], a[i-1]);
                count++;
                flag = true;
            }
        }
    }
    for(int i = 0; i < n-1; ++i) cout << a[i] << ' ';
    cout << a[n-1] << endl << count << endl;
    return 0;
}
