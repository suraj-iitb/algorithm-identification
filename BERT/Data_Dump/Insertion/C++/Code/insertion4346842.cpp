#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();


void insertionSort(int A[],int N){
    for (int i = 0; i < N; i++)
    {
        int v = A[i];
        int j = i-1;
        while (j>=0&&A[j]>v){
            A[j+1] = A[j];
            j--;    
        }
        A[j+1] = v;
        for (int k = 0; k < N-1; k++)
        {
            printf("%d ",A[k]);
        }
        
        printf("%d\n",A[N-1]);
    }
    return ;
}




int main()
{
    int N;
    scanf("%d",&N);
    int A[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&A[i]);
    }
    insertionSort(A,N);
    return 0;
}

