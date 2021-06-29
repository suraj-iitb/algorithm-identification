#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <functional>
#include <fstream>
#include <cstdlib>
typedef long long ll;
const int MOD = 1e9+7;


#define REP(i, N) for (int i = 0; i < (N); i++)
#define REPP(i, a, b) for (int i = (a); i < (b); i++)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define VSORT(c) sort((c).begin(),(c).end())
#define SZ(x) ((int)(x).size())
//vvintを作る　マクロで　 #define vvint(N,M) vector<vector<int>>

using namespace std;
int n;
void  countingSort(int A[],int B[],int k){
    int C[k];
    for(int i = 0; i < k+1;i++) C[i]=0;

    for(int i = 0; i < n;i++){
        C[A[i]]++;
    }

    for(int i = 1; i < k;i++){
        C[i]+=C[i-1];
    }

    for(int i = n-1; i >= 0 ;i--){
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }
}


int main(){
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    int A[n];
    int B[n];
    int _max = 0;
    for(int i = 0; i < n;i++){
        cin >> A[i];
        _max = max(_max,A[i]);
    }

    countingSort(A,B,max(_max,n)+1);

    for(int i = 0; i < n;i++){
        if(i){
           cout << " "; 
        }
        cout << B[i];
    }
    cout << endl;
    

    return 0;
}
