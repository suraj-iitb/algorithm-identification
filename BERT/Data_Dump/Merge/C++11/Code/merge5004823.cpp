#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<list>
#include<set>
#include<bitset>

#define rep(i,n) for(int i=0; i<(n); i++)
#define fixed_setprecision(n) fixed << setprecision((n))
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

using namespace std;
using ll =long long;
using P = pair<int,int>;

int cnt;
int L[500000];
int R[500000];

void merge(int A[], int left, int mid, int right){
    int INFTY = 1e9+1;
    int n1 = mid - left;
    int n2 = right - mid;
    rep(i, n1) L[i] = A[left + i];
    rep(i, n2) R[i] = A[mid + i];
      
    L[n1] = INFTY;
    R[n2] = INFTY;
    int i = 0;
    int j = 0;
    for(int k = left; k<right; k++){
        cnt++;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i = i + 1;
        }else{
            A[k] = R[j];
            j = j + 1;
        }
    }
}

void mergeSort(int A[], int left, int right){
    if(left+1 < right){
        int mid = (left + right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}



int main() {
    int n;
    cin >> n;
    
    int A[500000];
    rep(i, n) cin >> A[i];
     
    mergeSort(A, 0, n);
    rep(i, n-1) cout << A[i] << ' ';
    cout << A[n-1] << endl;
    cout << cnt << endl;
    
    return 0;
}

