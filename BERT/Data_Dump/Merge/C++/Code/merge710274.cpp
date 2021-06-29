#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt;

void Merge(vector<int>& v, int left, int mid, int right)
{
    int n1 = mid - left, n2 = right - mid;
    vector<int> L(n1 + 1),R(n2 + 1);
    for(int i = 0; i < n1; ++i) L[i] = v[left + i];
    for(int i = 0; i < n2; ++i) R[i] = v[mid + i];
    L[n1] = R[n2] = 1 << 30;
    int i = 0, j = 0;
    for(int k = left; k < right; ++k){
        cnt++;
        if(L[i] <= R[j]){
            v[k] = L[i];
            ++i;
        } else {
            v[k] = R[j];
            ++j;
        }
    }
}

void MergeSort(vector<int>& v, int left, int right)
{
    if(left + 1 < right){
        int mid = (left + right) / 2;
        MergeSort(v,left,mid);
        MergeSort(v,mid,right);
        Merge(v,left,mid,right);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    
    MergeSort(v,0,n);
    
    for(int i = 0; i < n; ++i){
        if(i != 0) cout << ' ';
        cout << v[i];
    }
    cout << endl;
    cout << cnt << endl;
}
