//typedef long long ll;    
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
    for (int i=0;i<n;i++) {    
        for (int j=n-1;j>i;j--) {    
            if (nums[j-1] > nums[j]) {      
                swap(nums[j-1],nums[j]);    
                cnt++;    
            }    
        }    
    }    
    trace(nums, n);    
    cout << cnt << endl;                
     
}    
    
int main() {    
    solve();    
}    
