#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;
#define EPS 1e-9
#define INF 0x3f3f3f
#define N 100000 + 5
#define M 10000 + 5
#define MM(X) memset(X , 0 , sizeof(X))
#define MZ(X) memset(X , 0xff , sizeof(X))
#define MI(X) memset(X , 0x3f , sizeof(X))
#define Fi(n) for( int i = 0 ; i < n  ; i ++ )
#define Fj(n) for( int j = 0 ; j < n  ; j ++ )
#define Fk(n) for( int k = 0 ; k < n  ; k ++ )
int main(){
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n ;
    while(cin >> n ){
        int num;
        int arr[105];
        Fi(n){
            cin >> arr[i];
        }
        Fi(n){
            int v = arr[i] ;
            int j = i - 1 ;
            while( j >= 0 && arr[j] > v ){
                arr[j+1] = arr[j] ;
                j --;
            }
            arr[j+1] = v ;
            Fk(n){
                if( k != 0 ){
                    cout << " " ;
                }
                cout << arr[k];
            }
            cout << endl ;
        }
    }
    return 0 ;
}

