#include<iostream>
using namespace std;

int main(){
    int sum=0,A[101],N;
    bool flag=1;
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    
    for(int i=0;flag;i++){
        flag = 0;
        for(int j=N-1;j>i;j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                flag = 1;
                sum++;
            }
        }
    }
    
    for(int i=0;i<N;i++){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sum << endl;
    return 0;
}
