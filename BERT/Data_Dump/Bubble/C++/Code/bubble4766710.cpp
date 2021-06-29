#include<iostream>
#include<string>

using namespace std;

int BubbleSort(int A[ ]  , int n){
    int count = 0;
    bool flag = 1;
    for(int i = 0 ; flag ; i++){ // if the flag equals to 1 , the loop keeps going until the flag equals to zero.
        flag = 0 ;
        for(int j = n -1; j >= i + 1 ; j--){
            if(A[j] < A[j-1]){
                swap(A[j],A[j-1]);
                flag = 1;
                count++;

            }
        
        }
    }
    return count;
}

 



int main(){

    int n; 
    int  count;
    cin >> n ;
    int A[n];
    
    for(int i = 0 ; i < n ; i++){
        cin >> A[i];
    }
    
    count = BubbleSort(A , n);
    for(int i = 0; i < n ; i++){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
    
   return 0;
}
