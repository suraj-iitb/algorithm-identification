#include <iostream>
#include <string>
using namespace std;

int main(){
    
    int N;
    cin >> N;
    int A[N];
    for(int i=0;i<N;i++) cin >> A[i];
    

   //int N =5;
   //int A[5] = {5,3,2,4,1};
    int count=0;
    for (int i=0;i<N;i++){
        for (int j=N-1;j>i;j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                count++;
            }
        }
    }
    for(int i=0;i<N;i++) {
        if(i!=0)cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
}
