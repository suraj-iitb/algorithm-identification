#include<iostream>
using namespace std;

int main(){
    int sum=0,A[101],N;
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];

    for(int i=0;i<N-1;i++){
        int minj = i;
        for(int j = i+1;j<N;j++){
            if (A[j] < A[minj]){
                minj = j;
            }
        }
        if(minj!=i){
            swap(A[i],A[minj]);
            sum++;
        }
    }
    
    for(int i=0;i<N;i++){
        if(i) cout << " ";
        cout << A[i] ;
    }
    cout << endl;
    cout << sum << endl;
    return 0;
}
