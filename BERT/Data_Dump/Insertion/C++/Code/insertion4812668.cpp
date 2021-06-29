#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100;
int A[N];

void print_pass(int A[], int n){
    for(int i = 0; i < n; ++i){
        if(i > 0) 
            cout << " " ;
        cout << A[i];
        }
        cout << endl;
    }

void insertion_sort(int A[], int n){
    for(int i = 1; i < n; ++i){
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key){
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = key;
        print_pass(A, n);
    }
}


int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> A[i];
    }
    print_pass(A, n);
    insertion_sort(A, n);
    return 0;
}
 
