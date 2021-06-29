#include <iostream>
using namespace std;
int main(void){
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++) cin >> A[i];
     
    int count = 0;
    int min;
    for(int i=0;i<n;i++){
        min = i;
        for(int j=i;j<n;j++){
            if(A[j] < A[min]) min = j;
        }
        if(i!=min){
            count++;
            int tmp;
            tmp = A[i];
            A[i] = A[min];
            A[min] = tmp;
        }
    }

    for(int i=0;i<n;i++){
        cout << A[i];
        if(i==n-1){
            cout << endl;
        }else{
            cout << " ";
        }
    }    
    cout << count << endl;
 
    return 0;
}
