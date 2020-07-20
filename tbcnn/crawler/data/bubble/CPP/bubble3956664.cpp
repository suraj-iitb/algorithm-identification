#include<iostream>

using namespace std;
int ans = 0;
void swap(int* x, int* y){
    *x += *y;
    *y = *x - *y;
    *x = *x - *y;
}

void trace(int A[], int n){
    cout << A[0];
    for (int i = 1; i < n; i++)
    {
        cout << " " << A[i];
    }
    cout << endl;
}
void bubble_sort(int A[], int n){
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int i = n-1; i > 0; i--)
        {
            if (A[i] < A[i-1])
            {
                swap(A+i, A+i-1);
                ++ans;
                flag = true;
            }   
        }   
    }
}
int main(){
    int n, A[105]; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    bubble_sort(A, n);
    trace(A, n);
    cout << ans << endl;
}
