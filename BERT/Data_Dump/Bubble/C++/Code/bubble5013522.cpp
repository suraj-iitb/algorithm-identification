#include<iostream>
using namespace std;
int main(){
    int N, i, j, flag = 1, temp, count = 0;
    cin >> N;
    int A[N];
    for(i =0; i < N; i++)
        cin >> A[i];
    for(i = 0; i < N - 1 && flag == 1; i++){
        flag = 0;
        for(j = N - 1; j > i; j--){
            if(A[j] < A[j - 1]){
                temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
                flag = 1;
                count++;
            }
        }
    }
    for(i = 0; i < N-1; i++)
        cout << A[i] << ' ';
    cout << A[N-1] << endl;
    cout << count << endl;
    return 0;
}
