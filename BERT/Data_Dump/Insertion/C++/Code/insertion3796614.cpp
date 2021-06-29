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
    printf("\n");
}

void insertSort(int a[], int n){
    int j, i, v;
    for(i = 1;i<n;i++){
        v=a[i];
        j=i-1;
        while(j>=0&&a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        trace(a,n);
    }
}

int main(){
    int n;
    int a[100];
    
    scanf("%d", &n);
    REP(i, n)scanf("%d", &a[i]);
    
    trace(a,n);
    insertSort(a, n);
    
    return 0;
}
