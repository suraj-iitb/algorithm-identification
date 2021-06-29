#include<bits/stdc++.h>

using namespace std;

int selectionSort(int A[], int N){
    int count = 0;
    for(int i=0;i<N;i++){
        int minj=i;
        for(int j=i;j<N;j++){
            if(A[j]<A[minj]){
                minj = j;
            }
        }
        if(minj==i)continue;
        int tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;
        count++;
    }
    for(int i=0;i<N;i++){
        cout << A[i];
        if(i!=N-1)cout << " ";
        
    }
    cout << endl;
    cout << count << endl;
    return count;
}

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    selectionSort(A,N);

}
