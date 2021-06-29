#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <cmath>
#include <functional>
#include <fstream>
#include <cstdlib>
typedef long long ll;

#define REP(i, N) for (int i = 0; i < (N); i++)
#define REPP(i, a, b) for (int i = (a); i < (b); i++)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define VSORT(c) sort((c).begin(),(c).end())
#define SZ(x) ((int)(x).size())

using namespace std;
int selectionSort(int A[],int N){
    int sw = 0,minj;
    int tmp;
    for(int i = 0; i < N; ++i){
        minj = i;
        for(int j = i+1; j < N; j++){
            if(A[j] < A[minj]) minj = j;
        }
        tmp = A[i]; A[i] = A[minj];A[minj] = tmp;
        if(i != minj) sw++;
    }

    return sw;
}

int main(){
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,A[100],i,sw;
    cin >> N;
    REP(i,N){
        cin >> A[i];
    }

    sw = selectionSort(A,N);

    REP(i,N){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl << sw << endl;

    

    return 0;
}
