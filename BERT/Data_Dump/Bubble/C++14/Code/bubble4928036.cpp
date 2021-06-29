#include <iostream>
using namespace std;

int bubblesort(int N, int A[]){
    int frag=1;
    int count=0;
    while (frag){
        frag = 0;
        for (int i=N-1; i>0; i--){
            if (A[i] < A[i-1]){
                int v = A[i];
                A[i] = A[i-1];
                A[i-1] = v;
                count += 1;
                frag = 1;
            }
        }
    }
    return count;
}

int main(){
    int N;
    cin >> N;
    int A[N];
    for (int i=0; i<N; i++) cin >> A[i];
    int count = bubblesort(N,A);
    for (int j=0; j<N; j++){
        if (j==N-1) cout << A[j] << "\n";
        else cout << A[j] << " ";
    }
    cout << count << "\n";
    
    return 0;
}
