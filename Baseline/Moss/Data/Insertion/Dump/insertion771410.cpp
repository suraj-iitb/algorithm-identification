#include <iostream>
using namespace std;
#define MAX 101

int main(){
    int n,A[MAX];
    
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> A[i];
    }
    
    for(int i = 1 ; i <= n ; i++){
        if(i==1) cout << A[i];
        else cout << ' ' << A[i];
    }
    cout << endl;
    
    for(int j = 2 ; j <= n ; j++){
        int key = A[j] ,i = j-1;

        while(i > 0 && A[i] > key){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
        
        for(int i = 1 ; i <= n ; i++){
            if(i==1) cout << A[i];
            else cout << ' ' << A[i];
        }
        cout << endl;
    }
    
    return 0;
}
