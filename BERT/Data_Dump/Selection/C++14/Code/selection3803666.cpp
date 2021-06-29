#include <iostream>
#include <string>
using namespace std;

int main(){
    
    int N;
    cin >> N;
    int A[N];
    for(int i=0;i<N;i++) cin >> A[i];
    /*
    int N =5;
    int A[5] = {5,3,2,4,1};
*/
    int minj;
    int sw=0;

    for(int i=0;i<N;i++){
        minj = i;
        for(int j=i+1;j<N;j++){
            if(A[j]<A[minj]) minj = j;
        }
        swap(A[i],A[minj]);
        if(minj != i) sw++;
    }
    for(int i=0;i<N;i++){
        if (i != 0) cout << " ";
        cout << A[i];
    }
    cout << endl << sw << endl;;
    
}
