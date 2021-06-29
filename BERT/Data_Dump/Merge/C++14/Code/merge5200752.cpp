#include <iostream>
#include <algorithm>
#include <vector> //動的配列
#include <string>
#include <list> //双方向リスト
#include <map> //連想配列
#include <set> //集合
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <numeric>
#include <tuple>



typedef long long ll;


using namespace std;

typedef pair<int, int> P;
#define FOR(i,a,b) for(int i=(int)(a) ; i < (int) (b) ; ++i )
#define rep(i,n) FOR(i,0,n)
#define sz(x) int(x.size())

vector<ll> lst;
int cnt=0;


void mergeSort(int l, int r){
    if (l+1<r){
        int mid=(r+l)/2;
        mergeSort(l,mid);
        mergeSort(mid,r);
        
        vector<int> leftList(mid-l), rightList(r-mid);
        rep(i,mid-l){
            leftList[i]=lst[i+l];
        }
        rep(i,r-mid){
            rightList[i]=lst[i+mid];
        }
        
        int s=0,t=0;
        FOR(i,l,r){
            cnt++;
            if (leftList.size()<=s) {
                lst[i]=rightList[t];t++;
            } else if (rightList.size()<=t){
                lst[i]=leftList[s];s++;
            }
            
            
            else if (leftList[s]<rightList[t]){
                lst[i]=leftList[s];
                s++;
            }else{
                lst[i]=rightList[t];
                t++;
            }
        }
        
    }
    
    
    return ;
}

int main(){
    int n; //cnt=0;
    cin>>n;
    lst.resize(n);
    rep(i,n){
        cin>>lst[i];
    }
    mergeSort(0,n);
    
    rep(i,n-1){
        cout<<lst[i]<<" ";
    }cout<<lst[n-1]<<endl;
    cout<<cnt<<endl;
    
    return 0;
}
