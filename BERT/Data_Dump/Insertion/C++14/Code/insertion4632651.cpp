#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int A[N];
    
    for(int a = 0;a<N;a++){
        cin >> A[a];
        if(a!=N-1){
            cout << A[a] << " ";
        }else{
            cout << A[a] << endl;
        }
    }
    for(int i = 1;i<N;i++){
        int v = A[i],j = i-1;
        while(j>=0&&A[j]>v){
            A[j+1]=A[j];
            j--;
            A[j+1] = v;
        }
        for(int a = 0;a<N;a++){
            if(a!=N-1){
                cout << A[a] << " ";
            }else{
                cout << A[a] << endl;
            }
        }
    }
    return 0;
}
