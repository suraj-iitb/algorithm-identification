#include <iostream>
 
using namespace std;
 
int main() {
    int i,j;
    int N, A[100];
    int s_c=0; //swap_count
    int mini_sub;
    
    //input
    cin >> N;
    for(i=0;i<N;i++) cin >> A[i];
    
    //書いてある疑似コード（pseudocode）通りだと、同じところ同士を調べたりしてるけど、そのまんま書く
    for(i=0;i<N;i++){
        mini_sub=i;
        for(j=i;j<N;j++){
            if(A[j]<A[mini_sub]) mini_sub=j;
        }
        if(i!=mini_sub){
            swap(A[i],A[mini_sub]);
            s_c++;
        }
    }
    
    //output
    for(i=0;i<N;i++){
        cout << A[i];
        if(i!=N-1) cout << ' ';
        else cout << endl;
    }
    cout << s_c++ << endl;
    
        return 0;
}
 
