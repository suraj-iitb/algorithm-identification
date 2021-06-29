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
    int n,j,c;
    int a[107];
    cin >> n;
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        rep(j,i){
            if(a[j]>a[i]){
                c=a[i];
                for(int k=i;k>j;k--){
                    a[k]=a[k-1];
                }
                a[j]=c;
                break;
            }
        }
    rep(j,n){
            cout  << a[j] ;
            if(j!=n-1)  cout << " ";
        }
        cout <<endl;
    }
}
