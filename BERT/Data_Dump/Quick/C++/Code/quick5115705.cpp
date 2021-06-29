#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

struct card{
    //カードのアルファベット
    char c;
    //カードの数字
    int val;
    //出現する順番
    int num;
};

//p番目からr-1番目までをソート
void quickSort(vector<card> &a, int p, int r){
    if(p+1<r){
        //xをピボットとして入れ替え
        int x = a[r-1].val;
        int i = p-1;
        for(int j=p;j<r;j++){
            if(a[j].val<=x){
                i = i+1;
                swap(a[i],a[j]);
            }
        }
        //より狭い範囲について再帰で繰り返し
        quickSort(a,p,i);
        quickSort(a,i,r);
    }
}

string isStable(vector<card> a){
    rep(i,a.size()-1){
        if(a[i].val==a[i+1].val && a[i].num>a[i+1].num) return "Not stable";
    }
    return "Stable";
}

int main(){
    int n;
    cin>>n;
    vector<card> a(n);
    rep(i,n){
        cin>>a[i].c>>a[i].val;
        a[i].num = i;
    }
    quickSort(a,0,n);
    
    cout<<isStable(a)<<endl;
    rep(i,n){
        cout<<a[i].c<<" "<<a[i].val<<endl;
    }
    return 0;
}
