#include <bits/stdc++.h>
typedef long long ll;
#define REP(i,n) for(int i=0;i<n;i++)
#define ALL(x) (x).begin(),(x).end()
using namespace std;



void trace(int A[],int N){
    REP(i,N){
        if(i>0)printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
}


int main(){
    int N;
    cin >> N;
    int r[N];
    REP(i,N)cin >> r[i];
    int count = 0;
    REP(i,N){
        int minj = i;
        for(int j=i;j<N;j++){
            if(r[j] < r[minj])minj = j;
        }
        int v = r[i];
        r[i] = r[minj];
        r[minj] = v;
        if(i!= minj)count++;
    }


    trace(r,N);
    cout << count << endl;
}

