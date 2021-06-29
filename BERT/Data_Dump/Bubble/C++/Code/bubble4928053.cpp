#include<iostream>
using namespace std;

int main(){

    int n,A[100];
    int flag = 1;
    int count = 0;

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> A[i];
    }

    while (flag){

        flag = 0;

        for (int j = n - 1; j >= 1; j--){

            if(A[j] < A[j - 1]){

                swap(A[j],A[j - 1]);
                count += 1;
                flag = 1;

            }
        }
    }

    for (int i = 0; i < n; i++){
            if (i != n - 1){
                cout << A[i] << " ";
            } else {
                cout << A[i] << endl;
            }
    }

    cout << count << endl;

    return 0;

}
