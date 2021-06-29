#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) (a).begin(),(a).end()
int cnt;
void buble_sort(int a[], int n){
    int flag = 1;
    while(flag){
        flag = 0;
        for(int j=n-1;j>0;j--)if(a[j] < a[j-1]){
            swap(a[j], a[j-1]);
            cnt++;
            flag = 1;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int r[n];
    rep(i,n)cin >> r[i];
    buble_sort(r, n);
    rep(i,n){
        cout << r[i];
        if(i < n-1)printf(" ");
        else printf("\n");
    }
    cout << cnt << endl;
    return 0;
}
