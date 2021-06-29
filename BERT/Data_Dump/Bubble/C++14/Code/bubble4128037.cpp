#include <iostream>

using namespace std;

void trace(int A[], int N){
    for(int i = 0; i < N;i++){
        if(i)printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

int bubble_sort(int A[], int N){
    int nsw = 0;
    for(int i = 0;i < N;i++){
        for(int j = N-1;j >= i+1;j--){
            if(A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                nsw++;
            }
        }
    }
    return nsw;
}

int main(){
    int n,A[100], nsw;
 
    cin >> n;
    for(int i = 0;i< n;i++){
        cin >> A[i];
    }

    nsw = bubble_sort(A, n);

    trace(A, n);
    cout << nsw << endl;
    return 0;
}
