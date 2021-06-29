#include<iostream>
using namespace std;
int main(){
    int N,v,j;
    int A[1000];
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    
    for(int i=0;i<N;i++){
        v = A[i];
        j = i-1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
            A[j+1] = v;
        }
        for(int i=0;i<N;i++){
            if(i==N-1){
                cout << A[i] << endl;
            }else{
                cout << A[i] << " ";
            }
        }
    }
}
