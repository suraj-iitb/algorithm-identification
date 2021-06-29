#include<iostream>
using namespace std;

int bubble(int A[],int n){
    int cou = 0;
    bool flag = 1;
    for (int i =0;flag;i++){
        flag =0;
        for (int j = n-1; j>=i+1; j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                flag = 1;
                cou++;
            }
        }
    }
    return cou;
}

int main(){
    int n;
    int A[100];
    int cou;
    
    cin  >> n;
    for (int i = 0; i<n; i++) cin >> A[i];
    
    cou =bubble(A,n);
    
    for(int i =0; i <n;i++){
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cou << endl;
    
    return 0;
}
