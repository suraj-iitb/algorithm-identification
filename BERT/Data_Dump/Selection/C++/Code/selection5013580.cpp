#include<iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    int A[N], i, j, min, temp, count = 0;
    for(i = 0; i < N; i++)
        cin >> A[i];
    for(i = 0; i < N-1; i++){
        min = i;
        for(j = i + 1; j < N; j++){
            if(A[min] > A[j])
                min = j;
        }
        if(i != min){
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
            count++;
        }
    }
    for(i = 0; i < N; i++){
        if(i) cout << ' ';
        cout << A[i];
    }
    cout << endl << count << endl;
    return 0;
}
