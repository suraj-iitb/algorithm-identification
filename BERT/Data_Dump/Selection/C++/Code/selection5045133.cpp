#include <bits/stdc++.h>    
using namespace std;    
    
void trace(int array[], int n) {    
    for (int i=0;i<n;i++) {    
        if (i == n-1) {    
            cout << array[i];    
        } else {    
            cout << array[i] << " ";    
        }    
    }    
    cout << endl;    
}    
    
void solve() {    
    int n;    
    cin >> n;    
    int nums[n];    
    for (int i=0;i<n;i++) {    
        cin >> nums[i];    
        //cout << nums[i];    
    }    
    
    int cnt = 0;    
    for (int i=0;i<n-1;i++) {    
        int min = nums[i];    
        int k = i;    
        for (int j=i ;j<n;j++) {    
            if (nums[j] < min) {    
                min = nums[j];    
                k = j;    
            }    
        }    
        if (i != k) {    
            swap(nums[i],nums[k]);    
            cnt++;    
        }    
    }    
    trace(nums, n);    
    cout << cnt << endl;    
    
}    
    
int main() {    
    solve();    
}    

