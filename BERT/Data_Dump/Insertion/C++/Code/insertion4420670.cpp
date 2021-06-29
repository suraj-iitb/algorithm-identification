# include<iostream>
using namespace std;
static const int MAX = 1000;

void output(int A[],int N){
    for(int i=0;i<N;i++){
        cout << A[i];
        if(i == N-1){
            cout << endl;
        }else{
            cout << " ";
        }
    }
}

void insertionSort(int A[],int N){
    int v,j;
    for(int i=1;i<N;i++){
        output(A,N);
        v = A[i];
        j = i - 1;
        while(j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1]=v;
    }
}
int main(){
    int N;
    int A[MAX];
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    insertionSort(A,N);
    output(A,N);
    return 0;
}
