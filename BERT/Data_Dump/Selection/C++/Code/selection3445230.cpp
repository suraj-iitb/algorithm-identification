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
#define int long long
typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii> > RPQ;
#define mk make_pair
#define INF (1 << 30)
#define INFL (1ll << 60ll)
#define mod 1000000007

int N, a[100100];

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 0; i < N; i++){
        int minj = i;
        for(int j = i; j < N; j++){
            if(a[j] < a[minj]){
                minj = j;
            }
        }
        if(i != minj){
            swap(a[i], a[minj]);
            cnt++;
        }
    }
    for(int i = 0; i < N; i++){
        cout << a[i] << ((i == N - 1) ? "\n" : " ");
    }
    cout << cnt << endl;


    return 0;
}

/*

*/
