#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>

#define FOR(i,a,b) for(int i =(a) ; i <= (b); i++)
#define REP(i,n)  FOR( i, 0, (n) - 1 )
#define INF (1 << 30)
#define FI first
#define SE second
#define pb push_back
#define mp make_pair
#define ALL(c) (c).begin(),(c).end()

using namespace std;

typedef long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};


int cnt = 0;

void Merge(vi &A, int left,int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    vi L(n1+1),R(n2+1);
    REP(i,n1) L[i] = A[left + i];
    L[n1] = INF;
    REP(i,n2) R[i] = A[mid + i];
    R[n2] = INF;
    
    int i=0,j=0;
    FOR(k,left,right-1){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        cnt++;
    }
}

void MergeSort(vi &A, int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        MergeSort(A, left, mid);
        MergeSort(A, mid , right);
        Merge(A, left, mid, right);
    }
}

int main(){
    int N;
    scanf("%d",&N);
    vi A(N);
    REP(i,N) scanf("%d",&A[i]);
    MergeSort(A, 0, N);
    REP(i,N){
        if(i) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
    printf("%d\n",cnt);
    return 0;
    
}
