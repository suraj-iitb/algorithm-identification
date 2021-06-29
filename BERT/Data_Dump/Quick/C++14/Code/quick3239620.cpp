#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<utility>
#include<map>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define REPR(i,n) for(int i=n-1;i>=0;i--)
#define FORR(i,n,m) for(int i=n-1;i>=m;i--)
#define all(in) in.begin(),in.end()
#define ALL(in,K) in,in+K
#define INF 1e18
#define MOD 100000007
#define SIZE 100005
#define PI 	3.14159265358979323846

int n;
int a[100000];
int b[100000];
int debag = 0;

char c[100000];

void Qsort(int begins,int ends){
    int pivot = begins;//境目
    FOR(i,begins,ends){
        if(a[i] <= a[ends-1]){
            swap(a[i],a[pivot]);
            swap(b[i],b[pivot]);
            swap(c[i],c[pivot]);
            pivot++;
        }
    }
    bool sorted = 1;
    FOR(i,begins,ends-1){
        if(a[i]<=a[i+1])sorted = 0;
    }
    if(sorted)return;
    Qsort(begins,pivot-1);
    Qsort(pivot,ends);
    return ;
}

int main(){
    cin >> n;
    REP(i,n){
        cin >> c[i] >> a[i];
        b[i] = i;
    }
    Qsort(0,n);
    bool isStable = 1;
    REP(i,n-1){
        if(a[i] == a[i+1]){
            if(b[i] > b[i+1]){
                cout << "Not stable" << endl;
                isStable = 0;
                break;
            }
        }
    }
    if(isStable)cout << "Stable" << endl;
    REP(i,n)cout << c[i] << " " <<a[i] << endl;
}
