#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int A[100];
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    
    int count=0;
    int flag=1;
    while(flag==1){
        flag=0;
        for(int j=n-1; j>0; j--){
            int v;
            if(A[j] < A[j-1]){
                v = A[j];
                A[j] = A[j-1];
                A[j-1] = v;
                count++;
                flag=1;
            }
        }
    }
    
    for(int k=0; k<n; k++){
        if(k>0) cout << " ";
        cout << A[k];
    }
    cout <<endl;
    
    cout << count << endl;
    
    return 0;
}

