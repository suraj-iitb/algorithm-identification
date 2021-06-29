//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define REP(i,n)  for(int i=0;i<(n);i++)

int selectionSort(int a[], int n){
    int i,j,t,cnt=0,minj;
    for(i=0;i<n-1;i++){
        minj = i;
        for(j=i;j<n;j++){
            if(a[j]<a[minj]) minj = j;
        }
        t = a[i]; a[i] = a[minj]; a[minj] = t;
        if(i!=minj)cnt++;
    }
    return cnt;
}

int main(){
    int a[100],n;
    cin>>n;
    REP(i, n)cin>>a[i];
    
    int cnt = selectionSort(a, n);
    
    REP(i, n){
        if(i)cout<<" ";
        cout<<a[i];
    }
    
    cout<<endl;
    cout<<cnt<<endl;

    
    return 0;
}
