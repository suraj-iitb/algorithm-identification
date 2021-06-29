#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    int nums = 0;
    bool flag = true;
    while(flag){
        flag = false;
        for(int j=N-1; j>=1; j--){
            if(A[j] < A[j-1]){
                nums += 1;
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = true;
            }
        }
    }

    for(int i=0; i<N-1; i++){
        cout << A[i] << " " ;
    }
    cout << A[N-1] << endl;
    cout << nums << endl;
}
