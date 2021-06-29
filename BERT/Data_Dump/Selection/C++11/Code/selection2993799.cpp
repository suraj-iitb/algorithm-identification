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

int selectionSort(vector<int> &A,int N){
    int count = 0;

    FOR(i,0,N){
        int min_index = i;
        FOR(j,i,N){
            if(A[j] < A[min_index]) min_index = j;
        }

        if(A[i] != A[min_index]) count++;

        swap(A[i],A[min_index]);

    }

    return count;

} 

int main(){
    int N;
    cin>>N;

    vector<int> A(N);
    FOR(i,0,N) cin>>A[i];

    int ans = selectionSort(A,N);

    cout<<A[0];
    FOR(i,1,N) cout<<" "<<A[i];

    cout<<"\n";
    put(ans);

}

