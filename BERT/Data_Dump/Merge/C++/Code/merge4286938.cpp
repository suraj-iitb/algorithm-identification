#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) (a).begin(),(a).end()
const int INF = pow(2, 31) - 1;
int cnt;
void merge(int a[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int l[n1+1], r[n2+1];
    rep(i,n1)l[i] = a[left + i];
    rep(i,n2)r[i] = a[mid + i];
    l[n1] = INF;
    r[n2] = INF;
    int i = 0, j = 0;
    REP(k,left,right){
        cnt++;
        if(l[i] <= r[j]){
            a[k] = l[i];
            i++;
        }else {
            a[k] = r[j];
            j++;
        }
    }
}

void merge_sort(int a[], int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        merge_sort(a, left, mid);
        merge_sort(a, mid, right);
        merge(a, left, mid, right);
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    rep(i,n)cin >> a[i];
    merge_sort(a, 0, n);
    rep(i,n){
        cout << a[i];
        if(i < n-1)printf(" ");
        else printf("\n");
    }
    cout << cnt << endl;
    return 0;
}
