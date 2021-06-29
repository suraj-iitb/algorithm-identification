#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) (a).begin(),(a).end()
int cnt;
void select_sort(int a[], int n){
    rep(i,n){
        int minj = i;
        bool change = false;
        REP(j,i,n)if(a[j] < a[minj]){
            minj = j;
            change = true;
        }
        swap(a[i], a[minj]);
        if(change)cnt++;
    }
}

int main(){
    int n;
    cin >> n;
    int r[n];
    rep(i,n)cin >> r[i];
    select_sort(r, n);
    rep(i,n){
        cout << r[i];
        if(i < n-1)printf(" ");
        else printf("\n");
    }
    cout << cnt << endl;
    return 0;
}
