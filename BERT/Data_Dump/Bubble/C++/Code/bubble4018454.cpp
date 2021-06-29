#include <iostream>
using namespace std;

int bubbleSort(int A[],int N){
    int count = 0;
    bool flag = 1;
    while(flag){
        flag = 0;
        for(int i=N-1;i>0;i--){
            if(A[i]<A[i-1]){
                swap(A[i],A[i-1]);
                count++;
                flag = 1;
            }
        
        }
    }
    return count;
}

int main(){
    int N;
    int A[100];
    int count;
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    count=bubbleSort(A,N);
    for(int i=0;i<N;i++){
        if(i!=N-1) cout << A[i] <<' ';
        else cout << A[i] << endl;
    }
    cout << count << endl;
    
    return 0;
}
