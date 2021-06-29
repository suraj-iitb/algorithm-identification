#include <bits/stdc++.h>

using namespace std;
int cnt;

void merge(vector<int> &a,int left,int mid,int right){
    int l_side = mid - left;
    int r_side = right - mid;
    int i = 0,j = 0;
    vector<int> l(l_side + 1),r(r_side + 1);
    
    for(i = 0;i<l_side;i++){
        l[i] = a[left + i];
    }
    
    for(i = 0;i<r_side;i++){
        r[i] = a[mid + i];
    }
    l[l_side] = 2000000000;
    r[r_side] = 2000000000;
    
    i = 0;
    j = 0;
    
    for(int k = left;k<right;k++){
        cnt++;
        if(l[i] <=r[j]){
            a[k] = l[i];
            i++;
        }else{
            a[k] = r[j];
            j++;
        }
    }
}

void mergesort(vector<int> &a,int n,int l,int r){
    if(l + 1 < r){
        int mid = (l + r) / 2;
        mergesort(a,n,l,mid);
        mergesort(a,n,mid,r);
        merge(a,l,mid,r);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    
    mergesort(a,n,0,n);
    
    for(int i = 0;i < n;i++){
        if(i)cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << cnt << endl;
}
