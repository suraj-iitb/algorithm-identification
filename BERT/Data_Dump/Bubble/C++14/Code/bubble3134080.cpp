#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

class BIT{
    long long *tree;
    int depth;

    public:
    BIT(unsigned int n){
        for(depth=0;(1<<depth)<n;depth++) ;
        tree = new long long[1<<depth]();
    }

    void add(unsigned int index, long long value){
        index++;
        for(;index<=(1<<depth);index+=index&-index){
            tree[index-1]+=value;
        }
    }

    long long sum(unsigned int index){
        index++;
        long long s=0;
        for(;index>0;index-=index&-index){
            s+=tree[index-1];
        }

        return s;
    }

    ~BIT(){
        delete[] tree;
    }
};

int main(){
    int N, A[100];
    cin >> N;
    BIT bit(101);
    for(int i=0;i<N;i++) cin >> A[i];

    ll cnt=0;
    for(int j=0;j<N;j++){
        cnt += j-bit.sum(A[j]);
        bit.add(A[j], 1);
    }

    sort(A,A+N);
    for(int i=0;i<N;i++) cout << A[i] << (i<N-1?' ':'\n');
    cout << cnt << endl;
    
    return 0;
}
