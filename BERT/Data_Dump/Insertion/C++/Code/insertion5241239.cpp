#include <iostream>
#include <algorithm>
using namespace std;
#include <stdio.h>
static const int MAX =100;
void insertionSort(int*,int);
void printarray(int*,int);
int main(){
    int N;
    cin >> N;
    int A[MAX];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    printarray(A,N);
    insertionSort(A,N);
    
    
    

}
void insertionSort(int A[],int N){
    int v,j;
    for (int i = 1; i < N; i++)
    {
        /* code */
        v=A[i];
        j=i-1;
        while (j>=0 && A[j]>v)
        {
            /* code */
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        printarray(A,N);
        
    }
    

}

void printarray(int A[],int N){
    for (int i = 0; i < N; i++) 
        {
            if (i==N-1)
            {
            cout <<A[i] << endl;
            }
            else{
                cout <<A[i] << " ";
                }
        
        
        }

}
