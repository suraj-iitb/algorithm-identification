#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int N,c,a;
    bool flag;
    cin >> N;
    flag = true;
    c = 0;
    int A[N];
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    
    while(flag){
        flag = false;
        for(int j=N-1;j>0;j--){
            if(A[j] < A[j-1]){
                swap(A[j],A[j-1]);
                flag = true;
                c++;
                
            }
        }
    }
    
    cout << A[0];
    for(int i=1;i<N;i++){
        cout << " " << A[i];
    }
    cout << endl;
    cout << c << endl;
    
}
