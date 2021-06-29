#include<iostream>
using namespace std;

int main(){
    int N,a=0,A[101];
    
    cin >> N;
    for (int i=0;i<N;i++) cin >> A[i];

    int flag = 1;
    while (flag){
        flag = 0;
        for (int j=N-1;j>0;j--){
            if (A[j]<A[j-1]){
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = 1;
                a++;
            }    
        }
    }

    for (int i=0;i<N;i++){
        if(i>0) cout << " ";
        cout << A[i];
    }
    cout << endl << a << endl;

    return 0;
}
