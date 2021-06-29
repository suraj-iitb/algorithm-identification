#include<iostream>
using namespace std;
int print(int *A,int N);
int print(int *A,int N)
{
    for(int i = 0;i < N-1;i++)
        cout << A[i] << " ";
    cout << A[N-1] << '\n';
    return 0;
}
int main(){
    int N,temp,i,j;
    cin  >> N;
    int A[N];
    for(int i = 0;i < N;i++)
        cin >> A[i];
    print(A,N);
    for(i = 1;i < N;i++){
        temp = A[i];
        for(j = i - 1;j >=0 && temp < A[j];j--)
            A[j+1] = A[j];
        A[j+1]=temp;
        print(A,N);
    }
    return 0;
}
