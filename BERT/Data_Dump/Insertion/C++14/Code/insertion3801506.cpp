#include <iostream>
#include <string>
using namespace std;

void output(int A[], int N){
    string out;
    for(int i = 0; i<N;i++){
        out += to_string(A[i]);
        if(i == N-1) out += '\n';
        else out += " ";   
    }
    cout << out;
}

int main() {
    int N;
    cin >> N;
    int A[N];
    int v;
    for (int i = 0;i<N; i++) cin >> A[i];
/*
N = 6;
int A[6] = {5,2,4,6,1,3};
*/
    for(int i = 0; i<N;i++){
        v = A[i];
        int j = i - 1;
        while(j >=0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        output(A,N);
    }
    return 0;

}
