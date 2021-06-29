#include<iostream>
using namespace std;

int insertionSort(int A[],int N){
    int v ,j ;

    for(int i = 1; i < N ; i++){
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;


        for(int i = 0; i < N ; i++){
               if( i == N - 1){
                   cout << A[i] << endl;
               }
               else{
                   cout << A[i] << " ";
               }
        }
      
    }

    return 0;
}

int main(){
    int a, X[1000];
    cin >> a;
    for(int i = 0; i < a; i++)cin >> X[i];
    for(int i = 0; i < a - 1 ; i++){
           cout << X[i] << " ";
        } 
    cout << X[a - 1] << endl;
    insertionSort(X,a);


    return 0;
}
