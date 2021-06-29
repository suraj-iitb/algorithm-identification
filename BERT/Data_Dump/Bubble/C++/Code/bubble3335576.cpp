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

//Aはソートする配列,jは交換する位置(j とj-1を入れ替える)
int* swap(int* A,int j){
    int tmp  = A[j];
    A[j] = A[j-1];
    A[j-1] = tmp;
    return A;
}




int main(){
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int A[N]; //ソートする配列
    int swapCount = 0;

    REP(i,N){
        cin >> A[i];
    }

    bool sortDoing = true;

    for(int i = 0;sortDoing;i++){
        sortDoing=false;
        for(int j = N-1; j >= i+1; --j){
            if(A[j] < A[j-1]){
                swap(A,j);
                swapCount++;
                sortDoing = true;
            }
        }
    }

    REP(i,N){
        if(i == N-1){
        cout << A[i] << endl;
        break;
        }
        cout << A[i] << " ";
    }
    cout << swapCount << endl;
    

    return 0;
}
