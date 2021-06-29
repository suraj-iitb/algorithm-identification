#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stack>
#include <climits>
#include <utility>
#include <cmath>

using namespace std;
typedef long long ll;

#define rep(i,n,m) for(int  i=n;i<=m;i++)
#define per(i,n,m) for(int i=n;i>=m;i--)
inline void scan(int&x){scanf("%d", &x);};inline void scan(ll&x){scanf("%lld",&x);};inline void scan(double&x){scanf("%lf",&x);};inline void scan(string&x){const char *str;scanf("%s",str);x = string(str);};inline void scan(char&ch){scanf("%c",&ch);};
inline void print(const int&x){printf("%d ",x);};inline void print(const ll&x) {printf("%lld ",x);};inline void print(const double&x) {printf("%lf ",x);};inline void print(const string&x){ const char *str=x.c_str();printf("%s ",str);};inline void print(const char&x) {printf("%c ",x);};
inline void println(const int&x){printf("%d\n",x);};inline void println(const ll&x) {printf("%lld\n",x);};inline void println(const double&x) {printf("%lf\n",x);};inline void println(const string&x){const char *str=x.c_str();printf("%s\n",str);};inline void println(const char&x) {printf("%c\n",x);};
inline void scanarray(int*a,int n){rep(i,0,n-1)scan(a[i]);};inline void scanarray(double*a, int n){rep(i,0,n-1)scan(a[i]);};
inline void printarray(int*a,int n){rep(i,0,n-2){print(a[i]);}println(a[n-1]);}inline void printarray(double*a, int n){rep(i,0,n-2){print(a[i]);} println(a[n-1]);};
inline void copyarray(int*a,int n,int*b){rep(i,0,n-1)b[i]=a[i];};inline void copyarray(double*a, int n, double*b){rep(i,0,n-1)b[i]=a[i];};
/*
scan, print, println    : int, ll, double, string, char
scanarray, printarray   : int, double
copyarray               : int to int, double to double
(*)scanarrayはすべての入力の型が同一でないとバグるので注意。 2 5.3 9 8　とかはダメ
stringについては入出力の際はchar*で行い、コード中で便利のためにstringを使えるようにしている
*/
const ll MaxN = 2000000;
ll A[MaxN];
int n;

void countingsort(int *A, int *B, int k) {
    int C[k];
    rep(i,0,k) {
        C[i] = 0;
    }
    rep(i,0,n-1) {
        C[A[i]]++;
    }
    rep(i,1,k) {
        C[i] = C[i] + C[i-1];
    }
    per(i,n-1,0) {
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }
    
}

int main() {
    //template
    
    scan(n);
    int a[n];
    int b[n];
    scanarray(a,n);
    
    int max=a[0];
    rep(i,0,n-1) {
        if(a[i] > max) max = a[i];
    }
    countingsort(a,b,max);
    
    printarray(b,n);
    

    return 0;
}


