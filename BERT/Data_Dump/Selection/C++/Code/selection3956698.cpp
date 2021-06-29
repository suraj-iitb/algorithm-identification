#include<iostream>

using namespace std;
int ans = 0;
void swap(int* x, int* y){
    *x += *y;
    *y = *x - *y;
    *x = *x - *y;
}
int insertion_sort(int A[], int n){
    int ans = 0;
    int min_A;
    for (int i = 0; i < n-1; i++)
    {
        min_A = i;
        for (int j = i+1; j < n; j++)
        {
            min_A = ((A[min_A] <= A[j]) ? min_A : j);
        }
        if(min_A!=i){
        swap(&A[min_A], &A[i]);
        ans++;
        }
    }
    return ans;
}

void trace(int A[], int n){
    cout << A[0];
    for (int i = 1; i < n; i++)
    {
        cout << " " << A[i];
    }
    cout << endl;
}

int main(){
    int n; cin >> n;
    int A[105];
    for (int i=0; i < n; i++)
        cin >> A[i];
    int ans = insertion_sort(A, n);
    trace(A, n);
    cout << ans << endl;
}
