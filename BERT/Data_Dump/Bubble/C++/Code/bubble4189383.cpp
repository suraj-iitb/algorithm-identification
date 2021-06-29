#include<iostream>
using namespace std;

int bubble(int A[],int N){
    int a=0;
    bool flag =1;
    for(int i=0;flag;i++){
        flag =0;
        for(int j=N-1;j>=i+1;j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                a++;
                flag=1;
            }
        }
    }
    return a;
}

int main(){
    int A[100],N,a;
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    
    a=bubble(A,N);
    
    for(int i=0;i<N;i++){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << a << endl;
    
    return 0;
}
