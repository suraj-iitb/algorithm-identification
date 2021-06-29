#include<iostream>
using namespace std;

int main(){
    int n;
    int A[100];
    int w,minj;
    int cou =0;
    
    cin >> n;
    for (int i =0;i<n;i++) cin >> A[i];
    
    for(int i = 0; i<n-1; i++){
        minj =i;
        for (int j =i; j<n; j++){
            if (A[j]<A[minj]) minj = j;
        }    
        w = A[i];
        A[i] = A[minj];
        A[minj] = w;
       
        if (i != minj) cou ++;
    }
    
    cout << A[0];
    for(int i =1; i<n; i++){
        cout << " "  << A[i];
    }cout << endl;
    
    cout << cou << endl;
    
    return 0;
}
