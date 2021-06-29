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

int main(){
    int n, cnt=0;
    cin>>n;
    vector<int> l(n);
    rep(i,n){
        cin>>l[i];
    }
    
    for(int i=0; i<l.size(); i++){
        for (int j=n-1; i<j; j--){
            if (l[j]<l[j-1]){
                cnt++;
                swap(l[j-1], l[j]);
            }
        }
    }
    
    rep(i,n-1){
        cout<<l[i]<<" ";
    }cout<<l[n-1]<<endl<<cnt<<endl;
    
    return 0;
}
