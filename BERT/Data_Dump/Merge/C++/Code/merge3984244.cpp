//  atcodder.xcode
//  main.cpp
//  Created by conan1024hao on 2019/11/11.
//  Copyright © 2019 conan1024hao. All rights reserved.
//  専用ライブラリ
#pragma GCC optimize ("O3")
#include <iostream>
#include <iomanip>
#include <istream>
#include <ostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll>P;
#define INF 10e16
#define MOD 1000000007
#define rep(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define fi first
#define se second
#define mmax(x,y)(x>y?x:y)
#define mmin(x,y)(x<y?x:y)
#define chmax(x,y) x=mmax(x,y)
#define chmin(x,y) x=mmin(x,y)
#define all(x) (x).begin(),(x).end()
#define PI acos(-1.0)
long long GCD(long long a, long long b) { return b ? GCD(b, a%b) : a; }
long long LCM(long long a, long long b)  {return a/GCD(a,b)*b;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
ll cmp(pair<ll,string>a,pair<ll,string> b){
        if(a.fi!=b.fi)
        return a.fi<b.fi;
        else
        return a.se<b.se;
}
//---------------------------------------------------------------------------
ll L[300000],R[300000],cnt;
vector<ll>a(500000);
void merge(int n,int l,int m,int r){
    int n1=m-l;
    int n2=r-m;
    for(int i=0;i<n1;i++){
        L[i]=a[l+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=a[m+i];
    }
    L[n1]=INF;
    R[n2]=INF;
    int i=0;
    int j=0;
    for(int k=l;k<r;k++){
        cnt++;
        if(L[i]<=R[j]){
            a[k]=L[i++];
        }
        else{
            a[k]=R[j++];
        }
    }
}
void mergesort(int n,int l,int r){
    if(l+1<r){
        int m=(l+r)/2;
        mergesort(n,l,m);
        mergesort(n, m, r);
        merge(n,l,m,r);
    }
}
//---------------------------------------------------------------------------
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    mergesort(n,0,n);
    for(int i=0;i<n;i++){
        if(i)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<cnt<<endl;
    //-------------------------------
    return 0;
}
//---------------------------------------------------------------------------

