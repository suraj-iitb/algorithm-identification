#include<iostream>
using namespace std;

int selectionSort(int A[], int N) {
        int minj,cnt = 0;

        for (int i=0;i<N;i++) {
        minj = i;
        for (int j=i+1;j<N;j++) {
        if (A[j] < A[minj])
        minj = j;
        }
        if (i != minj) {
        swap(A[i],A[minj]);
        cnt++;
        }
        }
        return cnt;
}

int main(){
        int N,cnt;
        cin >> N;
        int A[N];
        for (int i=0;i<N;i++)
        cin >> A[i];

        cnt = selectionSort(A,N);
        for (int i=0;i<N;i++)
        { if (i) cout << " ";
          cout << A[i];
        }
        cout << endl;
        cout << cnt << endl;

        return 0;
}
