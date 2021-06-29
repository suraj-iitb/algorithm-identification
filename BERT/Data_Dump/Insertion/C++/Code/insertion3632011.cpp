#include <iostream>
using namespace std;
int main(void){


    int n;
    cin >> n;
    int A[n];
    
    for(int i=0;i<n;i++) cin >> A[i];
    

    int key;
    int j;
    for(int i=0;i<n;i++){
        key=A[i];
        j = i-1;
        while(j>=0 and A[j] > key){
            A[j+1] = A[j];
            j--;
            A[j+1] = key;
        }
        
        for(int k=0;k<n;k++){
            if(k!=0) cout << " ";
            cout << A[k];
        }
        cout << endl;
        
    }
    

}

