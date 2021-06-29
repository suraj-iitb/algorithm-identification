#include <iostream>
#include <string>
#include <cstdio>
#define rep(i,n) Rep(i,0,n)
#define Rep(i,k,n) for(int i=k ; i<n ; i++)

const int INF = 1 << 30;
int cnt = 0;

using namespace std;

void Merge(int x[],int left, int mid, int right){
    //define range
    int n1 = mid - left;
    int n2 = right - mid;

    //working array
    int l[n1+10],r[n2+10];

    //init
    rep(i,n1) l[i] = x[left + i]; 
    rep(i,n2) r[i] = x[mid + i];

    //番兵
    l[n1] = r[n2] = INF;

    int il = 0;
    int ir = 0;
    

    for(int i = left; i < right ; i++){
        if(l[il] <= r[ir]){
            x[i] = l[il];
            il++;
        }else{
            x[i] = r[ir];
            ir++;
        }
        cnt++;
    }
}

void MergeSort(int x[],int left,int right){
    if(left+1 < right){
        int mid = (left + right)/2;

        MergeSort(x,left,mid);
        MergeSort(x,mid,right);
        Merge(x,left,mid,right);
    }
}

int main(){
    int n; cin >> n;
    int t[n];
    rep(i,n) cin >> t[i];

    
    MergeSort(t,0,n);
    
    rep(i,n) cout << t[i] << (i == n-1 ? '\n':' ');
    cout << cnt << endl;
    
}
