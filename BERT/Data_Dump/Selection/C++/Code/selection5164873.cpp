#include<bits/stdc++.h>

using namespace std;


int selectionSort(int A[], int n) {
    int tot = 0;
    for (int i = 0; i < n-1; i++) {
        int minj = i;
        for (int j = i; j < n; j++) {
            if (A[minj] > A[j]) {
                minj = j;

            }
        }
        if ( minj != i) {
            swap(A[minj], A[i]);
            ++tot;
        }

    }
    return tot;
}

int main() {
    int n,tot;
    int a[100];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    tot = selectionSort(a, n);

    for (int i = 0; i < n; i++) {
        if(i>0)cout<<" ";
      cout<<a[i];
    }
    cout << endl << tot<<endl;


    return 0;
}
