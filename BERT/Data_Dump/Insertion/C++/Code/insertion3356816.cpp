#include<iostream>
#include<algorithm>
using namespace std;
int MAX = 200;

void insertionSort(int *a, int n){
    int v,j;
    for(int i=1;i<n;i++){
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1]= v;
        for(int k = 0;k<n; k++){
            if(k>0) cout << " ";
            cout << a[k];
        }
        cout << endl;
    }

}

int main(){
    int A[MAX];
    int n;
    cin >> n;

    for(int i=0;i<n;i++) cin >> A[i];

        for(int k = 0;k<n; k++){
            if(k>0) cout << " ";
            cout << A[k];
        }
        cout << endl;
    insertionSort(A,n);


    return 0;
}
