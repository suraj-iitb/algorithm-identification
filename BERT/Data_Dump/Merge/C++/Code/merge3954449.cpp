#include <bits/stdc++.h>
#define INF 1e9
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i = 0; i < n; i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define max(v) *max_element(v.begin(), v.end())
#define min(v) *min_element(v.begin(), v.end())
using namespace std;

int a[500000];
long long cnt = 0;
void merge(int a[], int left, int mid, int right){
    int n1 = mid-left, n2 = right - mid;
    int l[n1+1], r[n2+1];
    for(int i = 0; i < n1; i++){
        l[i] = a[left + i];
    }
    for(int i = 0; i < n2; i++){
        r[i] = a[mid + i];
    }
    l[n1] = INF;
    r[n2] = INF;
    int i, j;
    i = 0;
    j = 0;
    for(int k = left; k < right; k++){
        if(l[i] <= r[j]){
            a[k] = l[i];
            i = i+1;
        }
        else{
            a[k] = r[j];
            j = j+1;
        }
        cnt += 1;
    }
}

void mergeSort(int a[], int left, int right){
    if(left+1 < right){
        int mid = (left + right)/2;
        mergeSort(a, left, mid);
        mergeSort(a, mid, right);
        merge(a, left, mid, right);
    }
}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    rep(i, n){
        cin>>a[i];
    }
    mergeSort(a, 0, n);
    rep(i, n){
        if(i == n-1){
            cout<<a[i]<<endl;;
        }
        else{
            cout<<a[i]<<" ";            
        }
    }
    cout<<cnt<<endl;
    return 0;
}

