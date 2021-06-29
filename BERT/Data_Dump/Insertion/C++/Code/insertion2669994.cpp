
#include <iostream>
using namespace std;

int main() {
    // insert code here...
    
    int i,j,k,N,V;
    int A[1000];
    
    cin >> N;
    
    for (i=0; i<N; i++){
        cin >> A[i];
    }

    for (k=0; k<N; k++){
        if (k==N-1)
        {
            cout << A[k] << endl;
        }
        else
        {
            cout << A[k] << flush;
            cout << " " << flush;
        }
    }
    
    for (i=1; i<N; i++){
        V=A[i];
        j=i-1;
        while (j>=0 and A[j]>V){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=V;
        for (k=0; k<N; k++){
            if (k==N-1)
            {
               cout << A[k] << endl;
            }
            else
            {
            cout << A[k] << flush;
            cout << " " << flush;
            }
        }
    }
    return 0;
}
