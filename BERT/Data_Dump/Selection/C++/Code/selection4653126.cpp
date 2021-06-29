#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int A[n] ={};
    for (int i=0;i<n;i++){
        cin >> A[i];
    }
    int a;
    int count =0;
    for (int i=0;i<n;i++){
        int mini=i;
        for (int j=i;j<n;j++){
            if(A[j]<A[mini]){
                mini = j;
            }
            
        }
        if (A[i] != A[mini]) count+=1;
        a = A[i];
        A[i] = A[mini];
        A[mini] = a;
    }
    
    for (int i=0;i<n;i++){
        cout << A[i];
        if (i!=n-1) cout <<" ";
        
        
    }
    cout << endl << count << endl;
    return 0;
}
