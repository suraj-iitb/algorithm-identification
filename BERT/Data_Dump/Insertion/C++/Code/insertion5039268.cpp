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
    
    for (int i=0;i<n;i++) {    
        int v = nums[i];    
        int j;     
        for (j = i-1;j >= 0;j--) {    
            if (nums[j] > v) {    
                nums[j+1] = nums[j];    
            } else {    
                break;    
            }    
        }    
        nums[j+1] = v;    
        trace(nums, n);    
    }    
    
}    
    
int main() {    
    solve();    
}  
