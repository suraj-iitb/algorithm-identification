#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) (a).begin(),(a).end()

void insert_sort(int a[], int n){
    REP(i,1,n){
        int v = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] >= v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;

        rep(j,n){
            printf("%d", a[j]);
            if(j < n-1)printf(" ");
            else printf("\n");
        }
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    rep(i,n)cin >> a[i];
    rep(j,n){
        printf("%d", a[j]);
        if(j < n-1)printf(" ");
        else printf("\n");
    }
    
    insert_sort(a, n);

    return 0;
}
