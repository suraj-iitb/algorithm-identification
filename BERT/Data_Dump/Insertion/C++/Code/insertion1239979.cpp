#include<iostream>
using namespace std;

void trace(int*,int);

#define MAX 1000


//Insertion Sort
int main(){
    int A[MAX];
    int N;
    int i;
    int j;
    int v;
    
    cin >> N;
    
    //input data
    for (i = 0;i < N;i++) {
        cin >> A[i];
    }

    trace(A,N);

    //Insertion Sort
    for (i = 1;i < N;i++) {
        v = A[i];
        j = i - 1;
        //compare
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        trace(A,N);
    }
}

//trace
void trace(int *A,int n)
{
    int i;

    for (i = 0; i < n; i++) {
        if (i) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
}
