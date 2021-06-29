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


int main(){
    int N;
    cin>>N;

    vector<int> A(N);
    FOR(i,0,N) cin>>A[i];


    cout<<A[0];
    FOR(i,1,N) cout<<" "<<A[i];


    FOR(i,1,N){
        RFOR(j,i,0){
            if(A[j] < A[j-1]) swap(A[j],A[j-1]);
        }
        cout<<"\n"<<A[0];
        FOR(i,1,N) cout<<" "<<A[i];
        
    }
    cout<<endl;
 
}
