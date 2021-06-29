#include <iostream>
#include <string>
#include <vector>

using namespace std;
void insertionSort(vector<int> &A,int N);
void PrintA(vector<int> &A,int N);

int main(){

    int N;
    
    cin >> N;

    vector<int> A(N);

    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    PrintA(A,N);

    insertionSort(A,N);

    return 0;
}

void PrintA(vector<int> &A,int N){

    for(int i=0;i<N;i++){
        cout << A[i];
        
        if(i == N-1){
            cout << endl;
        }
        else{
            cout << " ";
        }
    }
}

void insertionSort(vector<int> &A,int N){

    for(int i = 1; i < N; i++){

        int v = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--; 

        }
    A[j+1] = v;
    PrintA(A,N);
    }  
}  

