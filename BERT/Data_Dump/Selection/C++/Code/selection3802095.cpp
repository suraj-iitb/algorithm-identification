#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
using namespace std;
#define MOD 1000000007
#define EPS 10e-8

int main(){
    int n,mi,c,minplace,l;
    l=0;
    int a[107];
    cin >> n;
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        mi=a[i];
        minplace=i;
        for(int j=i;j<n;j++){
            if(a[j]<mi){
                mi=a[j];
                minplace=j;
            }
        }
        if(minplace!=i){
            c=a[minplace];
            a[minplace]=a[i];
            a[i]=c;
            l++;
        }
    }
    rep(i,n){
        cout << a[i];
        if(i!=n-1) cout << " ";
    }
    cout << endl << l << endl;
}
