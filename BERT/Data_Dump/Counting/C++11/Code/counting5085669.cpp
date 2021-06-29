#include <iostream>
using namespace std;

#define K 100000

//void countingsort(int *, int);
int A[2000000], B[2000000];

void countingsort(int n){
    int C[2000000];
    for(int i = 0; i < K; i++){
        C[i] = 0;
    }//初期化

    for(int i = 0; i < n; i++){
        C[A[i]]++;
    }//カウント
    
    /*for(int i = 0; i < 15; i++){
        cout << " C["<< i << "]:" << C[i] << endl; 
    }*/

    for(int i = 1; i < K; i++){
        C[i] = C[i] + C[i - 1];
    }

   /* for(int i = 0; i < 15; i++){
        cout << " C["<< i << "]:" << C[i] << endl; 
    }*/

    for(int i = n - 1; i >= 0; i--){
        C[A[i]]--;
        B[C[A[i]]] = A[i];
    }
}

int main(){
    int n;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    countingsort(n);
    for(int  i = 0; i < n; i++){
        if(i != n - 1)
            cout << B[i] << " ";
        else
            cout << B[i] << endl;
    }
    return 0;
}
