#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i = 0;i<N;i++){
        cin >> A[i];
    }
    int flag = 1,count = 0;
    while(flag){
        flag = 0;
        for(int j = N-1;j>0;j--){
            int v = A[j];
            if(A[j]<A[j-1]){
                A[j] = A[j-1];
                A[j-1] = v;
                count ++;
                flag = 1;
            }
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
