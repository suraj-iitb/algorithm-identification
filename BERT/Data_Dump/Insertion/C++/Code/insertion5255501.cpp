#include<iostream>
using namespace std;


int main(){
    int N, a, v, i, j, k;
    cin >> N;
    int A[100];
    for(i=0; i<N; i++){
        cin >> a;
        A[i] = a;
    }

    /*for(k=0; k<N; k++){
        if(k==N-1) cout << A[k] << endl;
        else cout << A[k] << " ";}
*/
    for(i=0; i<N; i++){
        v = A[i];
        j = i-1;
        while(j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
            A[j+1] = v;
        }
        for(k=0; k<N; k++){
            if(k==N-1) cout << A[k] << endl;
            else cout << A[k] << " ";
        }
    }
}
