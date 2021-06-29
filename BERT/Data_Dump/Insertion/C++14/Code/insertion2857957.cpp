#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i=0 ; i<N ; i++){
        cin >> A[i];
        if(i!=N-1){
            cout << A[i] << " ";
        }else{
            cout << A[i] << endl;
        }
    }
    for(int j=1 ; j<=N-1 ; j++){
        int v, k;
        v = A[j];
        k = j-1;
        while(k>=0 && A[k]>v){
            A[k+1] = A[k];
            k--;
        }
        A[k+1] = v;
        int l=0;
        while(l<N-1){
            cout << A[l] << " ";
            l++;
        }
        cout << A[l] << endl;
    }
    return 0;
}

