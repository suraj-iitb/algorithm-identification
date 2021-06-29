#include <iostream>
#include <algorithm>
using namespace std;

void print_array(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout << a[i];
        if(i!=n-1) cout << " ";
    }
    cout << endl;
}

int selectionSort(int A[], int N) {
    int count = 0;
    int minj;
    for(int i=0;i<N;i++){
        minj = i;
        for(int j=i+1;j<N;j++){
            if(A[j]<A[minj]){
                minj = j;
            }
        }
        if(minj != i){
            swap(A[i], A[minj]);
            count++;
        }
    }
    return count;
}

int main() {
    int A[100], N, count;
    cin >> N;
    for ( int i = 0; i < N; i++ ) cin >> A[i];
    
    count = selectionSort(A, N);
    
    print_array(A, N);
    cout << count << endl;
}
