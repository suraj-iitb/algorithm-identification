
//#include <assert.h>
#include <iostream>

using namespace std;
#define N 110
#define INPUT_MAX 1000

void print_array(int A[], int n);

void insertionSort(int A[], int n);

int main (void){

    int A[N];

    int n;

    cin >> n;


    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    insertionSort(A, n);


    return 0;

}

void print_array(int A[], int n){

    for(int i = 0; i < n-1; i++){
        cout << A[i]  << " ";
    }
    cout << A[n-1] << endl;


}

void insertionSort(int A[], int n){

    for(int i = 1; i < n; i++){
        print_array(A, n);
        


        int v = A[i];
        int j = i - 1;

        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        
    }

    print_array(A, n);
}
