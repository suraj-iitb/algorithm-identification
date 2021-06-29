#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 100;
const int MOD = 1000000007;

void doc() {
    freopen("OB.inp","r",stdin);
    freopen("OB.out","w",stdout);
    ///cerr << "OK" << '\n';
}

int res = 0;

void Merge(vector<int> &A, int l, int m, int r){
    //cout << l << " " << r << '\n';
    int n1 = m - l + 1;
    int n2 = r - m;
    int x[n1], y[n2];
    for(int i = 0; i < n1; i++) x[i] = A[i + l];
    for(int i = 0; i < n2; i++) y[i] = A[i + m + 1];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2){
        if (x[i] <= y[j]){
            A[k++] = x[i++];
            res++;
        }
        else{
            res++;
            A[k++] = y[j++];
        }
    }
    while (i < n1) {
        A[k++] = x[i++];
        res++;
    }
    while (j < n2) {
        A[k++] = y[j++];
        res++;
    }

}

void mergeSort(vector<int> &A, int l, int r){
    if (l >= r) return;
    int m = (l + r) >> 1;
    //cout << l << " " << r << '\n';
    mergeSort(A, l, m);
    mergeSort(A, m + 1, r);
    //cerr << l << " " << r << endl;
    Merge(A, l, m, r);
}

void solve() {
    int n;
    cin >> n;
    //int a[n];
    vector<int> a;
    for(int i = 0; i < n; i++)
        //cin >> a[i];
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    mergeSort(a, 0, n - 1);
    for(int i = 0; i < n-1; i++) printf("%d ",a[i]);
	printf("%d\n",a[n-1]);
	printf("%d\n",res);
}
int main(){
    //ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    //doc();
    solve();
}


