#include<iostream>
using namespace std;

int main(){
    int n;
    int A[100];
    cin >> n;
    for (int i =0; i<n; i++){
        cin >> A[i];
    }
    for(int i =0; i<n; i++){
        int v;
        v =A[i];
        int j = i-1;
        while(1){
            if (j<0 || A[j] <=v) break;
            A[j+1] = A[j];
            j--;
        A[j+1]  =v;
        }
           cout << A[0] ;
            for (int i =1;i<n; i++){
                cout << " " << A[i] ;
            }cout << endl;
    }
    return 0;
    
}
