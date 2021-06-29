#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cmpcount = 0;

void merge(vector<int> &a, int left, int mid, int right) {
    int n1 = mid - left, n2 = right - mid;
    vector<int> l(n1), r(n2);
    for(int i=0; i<n1; i++) l[i] = a[left + i];
    for(int i=0; i<n2; i++) r[i] = a[mid + i];
    int i=0, j=0;
    for(int k=left; k<right; k++) {
        cmpcount++;
        if(j==n2 || (i!=n1 && l[i] <= r[j])) {
            a[k] = l[i++];
        } else {
            a[k] = r[j++];
        }
    }
}

void mergesort(vector<int> &a, int left, int right) {
    if(left+1 < right) {
        int mid = (left + right) / 2;
        mergesort(a, left, mid);
        mergesort(a, mid, right);
        merge(a, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int i=0; i<n; i++) cin >> s[i];
    mergesort(s, 0, n);
    for(int i=0; i<n; i++) {
        cout << s[i] << (i==n-1 ? "\n" : " ");
    }
    cout << cmpcount << endl;
}
