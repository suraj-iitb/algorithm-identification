#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<stack>
#include<queue>
using namespace std;

typedef long long i64;
#define put(n) cout<<(n)<<"\n"
#define FOR(i,num,N) for(int(i)=(num);(i)<(N);(i)++)
#define RFOR(i,num,N) for(int (i)=(num);(i)>(N);(i)--)
#define all(v) (v).begin() , (v).end()
#define rall(v) (v).rbegin() , (v).rend()

int bubbleSort(vector<int> &A,int N){
    int count = 0; 
    bool end = false;
    while(!end){
        end = true;
        RFOR(i,N-1,0){
            if(A[i] < A[i-1]){
                swap(A[i],A[i-1]);
                end = false;
                count++;
            }
        }
    }
    return count;
}

int main(){
    int N;
    cin>>N;

    vector<int> A(N);
    FOR(i,0,N) cin>>A[i];

    int ans = bubbleSort(A,N);

    cout<<A[0];
    FOR(i,1,N) cout<<" "<<A[i];

    cout<<"\n";
    put(ans);
}
