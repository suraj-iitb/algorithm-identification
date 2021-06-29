#include <bits/stdc++.h>
using namespace std;

void show(int A[],int N){
    for(int i = 0; i < N;i++){
        if(i > 0) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
}

int selection(int A[],int N){
    int count = 0;
    for(int i=0; i < N-1; i++){
        int min = A[i];
        int index = i;
        for(int j = i+1; j < N; j++){
            if(A[j] < min){
                min = A[j];
                index = j;
            }
        }
        if(i != index){
            swap(A[i],A[index]);
            count++;
        }
    }
    return count;
}

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    int ans = selection(A,N);
    show(A,N);
    cout << ans << endl;
}
