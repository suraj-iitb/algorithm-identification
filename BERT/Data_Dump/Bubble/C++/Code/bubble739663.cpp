#include <iostream>
 
using namespace std;
 
int main() {
        int i,j;
    int N, A[100];
    int s_c=0; //swap_count
    
    cin >> N;
    for(i=0;i<N;i++) cin >> A[i];
    
    for(i=0;i<N;i++){
        for(j=N-1;j>i;j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                s_c++;
            }
        }
    }
    
    for(i=0;i<N;i++){
        cout << A[i];
        if(i!=N-1) cout << ' ';
        else cout << endl;
    }
    cout << s_c++ << endl;
    
        return 0;
}
