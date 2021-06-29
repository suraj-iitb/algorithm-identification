#include<iostream>
using namespace std;


int main(){
    int A[100], start , mini, b ,c = 0, n;
    cin >> n;
    for(int i = 0; i < n; i++)cin >> A[i];
    for(int i = 0; i < n - 1; i++){
        int d = i + 1;
        mini = A[i + 1];
        for(int j = i + 1; j < n - 1; j++){
            if (mini > A[j + 1]){
                mini = A[j + 1];
                d = j + 1;
            }
        }
        if(A[i] > mini){
            b = mini;
            A[d] = A[i];
            A[i] = b;
            c++;
        } 

    }
    



    for(int i = 0; i < n - 1; i++)cout << A[i] << " ";
    cout << A[n - 1] << endl;
    cout << c << endl;


}
