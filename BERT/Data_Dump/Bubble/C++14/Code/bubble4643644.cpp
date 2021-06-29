#include<iostream>
using namespace std;


int main(){
    int A[100], c = 0 ,b, n, s;
    cin >> n;
    for(int i = 0; i < n; i++)cin >> A[i];
    for(int i = 1; i < n; i++){
        for(int s = 1; s < n; s++){
            if(A[s - 1] > A[s]){
                b = A[s - 1];
                A[s - 1] = A[s];
                A[s] = b;
                c++;
            }
            //if(s == n)break;
        }

    }
    for(int i = 0; i < n - 1; i++)cout << A[i] << " ";
    cout << A[n - 1] << endl;
    cout << c << endl;


}

