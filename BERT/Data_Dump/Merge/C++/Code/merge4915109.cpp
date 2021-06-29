#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

//global
int n;
int cnt = 0;

void merge(int s[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;

    int l[n1 + 1];
    int r[n2 + 1];
    rep(i,n1 + 1) l[i] = s[left + i];
    rep(i,n2 + 1) r[i] = s[mid + i];
    l[n1] = 1000000001;
    r[n2] = 1000000001;

    int i = 0;
    int j = 0;
    for(int k = left; k < right; k++){
        cnt++;
        if(l[i] <= r[j]){
            s[k] = l[i];
            i++;
        }else{
            s[k] = r[j];
            j++;
        }
    }
}

void mergeSort(int s[], int left, int right){
    if(left + 1  < right){
        int mid = (left + right) / 2;
        mergeSort(s, left, mid);
        mergeSort(s, mid, right);
        merge(s, left, mid, right);
    }
}

int main(){
    cin >> n;

    int s[n];
    rep(i,n) cin >> s[i];

    mergeSort(s, 0, n);

    rep(i,n - 1) cout << s[i] << " ";
    cout << s[n - 1] << endl;

    cout << cnt << endl; 

    return 0;
}
