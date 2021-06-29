#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    int n, a[100], count = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];

    for(int i = 0; i < n; ++i){
        int minj = i;
        for(int j = i; j < n; ++j){
            if(a[j] < a[minj]) minj = j;
        }
        swap(a[i], a[minj]);
        if(i != minj) count++;
    }
    for(int i = 0; i < n-1; ++i) cout << a[i] << ' ';
    cout << a[n-1] << endl << count << endl;
    return 0;
}
