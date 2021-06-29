#include <bits/stdc++.h>
using namespace std;

void show(int A[],int N){
    for(int i = 0; i < N;i++){
        if(i > 0) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
}

int bubble(int A[],int N){
    int count = 0;
    for(int i = 0; i < N-1; i++){
        int j = N-1;
        while(j > i){
            if(A[j-1] > A[j]){
                swap(A[j-1],A[j]);
                count += 1;
            }
            j--;
        }
    }
    return count;
}

int main(){
    int N;
    int ans;
    cin >> N;
    int A[N];
    for(int i = 0; i < N;i++){
        cin >> A[i];
    }
    ans = bubble(A,N);
    show(A,N);
    cout << ans << endl;
}
