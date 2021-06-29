#include <iostream>
#include <vector>

using namespace std;

void Trace(int A[], int N){
    for(int i=0;i<N;++i){
        if(i>0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

int BubbleSort(int A[],int N){
    int sw=0;
    bool flag = 1;
    for(int i=0;flag;++i){
        flag = 0;
        for(int j=N-1;j>=i+1;--j){
            if(A[j]<A[j-1]){
                swap(A[j], A[j-1]);
                flag = 1;
                sw++;
            }
        }
    }
    return sw;
}

int main(){
    int N,sw;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    sw = BubbleSort(A, N);
    Trace(A, N);
    cout << sw << endl;

    return 0;

}
