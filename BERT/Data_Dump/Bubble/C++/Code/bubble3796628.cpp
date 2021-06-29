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

void trace(int a[], int n){
    REP(i, n){
        if(i>0)printf(" ");
        printf("%d",a[i]);
    }
}

int bubbleSort(int a[],int n){
    bool flag = 1;
    int i = 0,cnt=0;
    while(flag){
        flag = 0;
        for(int j=n-1;j>=i+1;j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                flag = 1;
                cnt++;
            }
        }
        i++;
    }
    return cnt;
}

int main(){
    int a[100],n,cnt;
    cin>>n;
    REP(i, n)cin>>a[i];
    
    cnt = bubbleSort(a, n);
    
    REP(i, n){
        if(i)cout<<" ";
        cout<<a[i];
    }
    
    cout<<endl;
    cout<<cnt<<endl;
    
    return 0;
}
