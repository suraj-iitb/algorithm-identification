#include<iostream>
using namespace std;

int main(void){

    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    int flag, v, count;

    flag = 1;
    count = 0;

    while(flag){

        flag = 0;

        for (int j = (N - 1); j > 0; j--){

            if (A[j] < A[j - 1]){
                v = A[j];
                A[j] = A[j - 1];
                A[j - 1] = v;
                flag = 1;
                count++;
            };

        }

    }

    for (int i = 0; i < N; i++){
        cout << A[i];
        if (i != (N - 1)) cout << " "; 
        else cout << endl;
    }

    cout << count << endl;

    return 0;
}
