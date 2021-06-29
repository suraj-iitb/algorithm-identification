#include <iostream>
using namespace std;

void swap(int *p_from, int *p_to) {
    int tmp;
    tmp = *p_from;
    *p_from = *p_to;
    *p_to = tmp;
}

int main(void){
    // Your code here!
    // N個の要素を含む0-オリジンの配列A
    int N, W;
    cin >> N;
    int A[N];
    
    //配列に数字を格納
    for(int j=0; j<N; j++){
        cin >> W;
        A[j] = W;
    }
    
    //並び替え
    for(int i=0; i<N; i++){
        for(int wk_i=0; wk_i < N -1; wk_i++){
            cout << A[wk_i] << " ";
        }
        cout << A[N-1] << endl;
        
        W=i;
        while(W>=0 && (A[W] > A[W+1])){
            swap(&A[W], &A[W+1]);
            W--;
        }
    }
     
    
}
