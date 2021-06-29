#include<iostream>

using namespace std;
const int MAX = 10005, N_MAX = 2000005;
int n;
void counting_sort(unsigned short A[], unsigned short B[], int k){
    int C[MAX];
    for (int i = 0; i < k; i++)
    {
        C[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        C[A[i]]++;
    }
    for (int i = 0; i < MAX-1; i++)
    {
        C[i+1] = C[i+1] + C[i];
    }
    for (int i = n-1; i >= 0; i--)
    {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
}

int main(){
    cin >> n;
    unsigned short A[N_MAX], B[N_MAX];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    counting_sort(A, B, MAX);
    cout << B[1];
    for (int i = 2; i < n+1; i++)
    {
        cout << " " << B[i];
    }
    cout << endl;
}
