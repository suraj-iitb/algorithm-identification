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
using namespace std;
//#define int long long
typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii> > RPQ;
#define mk make_pair
#define INF (1 << 30)
#define INFL (1ll << 60ll)
#define mod 1000000007

int N, A[500500], cnt;

void merge(int left, int mid, int right){
    int n1 = mid - left, n2 = right - mid;
    int L[n1 + 1] = {0}, R[n2 + 1] = {0};
    for(int i = 0; i < n1; i++){
        L[i] = A[left + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = A[mid + i];
    }
    L[n1] = INF;
    R[n2] = INF;
    int li = 0, ri = 0;
    for(int k = 0; k < right - left; k++){
        cnt++;
        if(L[li] <= R[ri]){
            A[left + k] = L[li];
            li++;
        }
        else {
            A[left + k] = R[ri];
            ri++;
        }
    }
}

void mergeSort(int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid, right);
    }
}

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    mergeSort(0, N);
    for(int i = 0; i < N; i++){
        cout << A[i] << ((i == N - 1) ? "\n" : " ");
    }
    cout << cnt << endl;

    return 0;
}

/*

*/
