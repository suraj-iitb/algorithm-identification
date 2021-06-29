#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define all_acc(x) (x).begin(),(x).end(),0LL
#define int long long
#define absSort(v) sort(a.begin(), a.end(), [](int i, int j) -> bool {return abs(i) < abs(j);});
using namespace std;
using P=pair<int,int>;
using Graph=vector<vector<int>>;
using ll=long long;

//出力するよ
void output(vector<int> s){
    int n=s.size();
    for(int i=0;i<n;i++){
        if(i!=0) cout<<" ";
        cout<<s[i];//<<endl;
    }
    cout<<endl;
}
int cnt;

void merge(vector<int> &a,int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    vector<int> l(n1+1);
    vector<int> r(n2+1);
    for(int i=0;i<n1;i++) l[i]=a[left+i];
    for(int i=0;i<n2;i++) r[i]=a[mid+i];

    l[n1]=pow(10,10);
    r[n2]=pow(10,10);
    int i=0,j=0;

    for(int k=left;k<right;k++){
        //ここが比較しているところ
        cnt++;
        if(l[i]<r[j]){
            a[k]=l[i];
            i++;
        }else{
            a[k]=r[j];
            j++;
        }
    }
}

void mergeSort(vector<int> &a,int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid,right);
        merge(a,left,mid,right);
    }
}

signed main(){
    int n; cin>>n;
    vector<int> s(n);
    cnt=0;
    for(int i=0;i<n;i++) cin>>s[i];

    mergeSort(s,0,n);
    output(s);
    cout<<cnt<<endl;
}
