#include<cstdio>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#include<functional>
#include<map>
#include<set>
using namespace std;
//#define int long long
typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii> > RPQ;
#define mk make_pair
#define INF (1 << 30)
#define INFL (1ll << 60ll)
#define mod 1000000007

int N, a[1010];

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        cout << a[i] << ((i == N - 1) ? '\n' : ' ');
    }
    for(int i = 1; i < N; i++){
        int v = a[i];
        int j = i - 1;
        while(j >= 0){
            if(a[j] <= v)break;
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        for(j = 0; j < N; j++){
            cout << a[j] << ((j == N - 1) ? '\n' : ' ');
        }
    }


    return 0;
}

/*

*/
