#include<iostream>
using namespace std;

int main(void) {
    int n, a[100];
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    // bubble sort
    int end_flag = 0, swap_num = 0;
    for(int j=0;!end_flag;j++){
        end_flag = 1;
        for(int i=n-1;i>j;i--){
            end_flag = 0;
            if(a[i] < a[i - 1]){
                swap(a[i], a[i - 1]);
                swap_num++;
            }
        }
    }
    // disp result
    for(int i = 0; i < n; i++){
        if(i) cout << ' ';
        cout << a[i];
    }
    cout << endl;
    cout << swap_num << endl;
    return 0;
}

