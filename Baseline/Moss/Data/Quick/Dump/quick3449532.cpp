#include<cstdio>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#include<functional>
#include<map>
#include<set>
#include<cstring>
#include<string>
#include<stack>
#include<malloc.h>
#include<math.h>
using namespace std;
//#define int long long
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef priority_queue<pii, vector<pii>, greater<pii> > RPQ;
#define mk make_pair
#define INF (1 << 30)
#define INFL (1ll << 60ll)
#define mod 1000000007

int N;
pic a[100100];

int partition(pic A[], int p, int r){
    int x = A[r].first;
    int i = p - 1;
    for(int j = p; j < r; j++){
        if(A[j].first <= x){
            i++;
            if(i != j)swap(a[i], a[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

void quicksort(pic A[], int p, int r){
    if(p >= r)return;
    int q = partition(A, p, r);
    quicksort(A, p, q - 1);
    quicksort(A, q + 1, r);
}

map<int, string> mp1, mp2;

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int x;
        char c;
        cin >> c >> x;
        a[i] = mk(x, c);
        mp1[x] += c;
    }
    quicksort(a, 0, N - 1);
    for(int i = 0; i < N; i++){
        mp2[a[i].first] += a[i].second;
    }
    string flag = "Stable";
    for(int i = 0; i < N; i++){
        if(mp1[a[i].first] != mp2[a[i].first]){
            flag = "Not stable";
        }
    }
    cout << flag << endl;
    for(int i = 0; i < N; i++){
        cout << a[i].second << " " << a[i].first << endl;
    }

    return 0;
}

/*

*/
