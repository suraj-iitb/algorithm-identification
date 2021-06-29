#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i = 0;i<N;i++){
        cin >> A[i];
    }
    int count = 0;
    int minj,v;
    for(int i = 0;i<N;i++){
        minj = i;
        v=A[i];
        for(int j = i;j<N;j++){
            if(A[j]<A[minj]){
                minj = j;
            }
        }
        if(i!=minj){
            A[i] = A[minj];
            A[minj] = v;
            count++;
        }
    }
    
    for(int i = 0;i<N;i++){
        if(i!=N-1){
            cout << A[i] << " ";
        }else{
            cout << A[i] << endl;
        }
    }
    cout << count << endl;
    return 0;
}
