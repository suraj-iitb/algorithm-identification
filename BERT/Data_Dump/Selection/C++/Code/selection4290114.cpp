
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
void trace(int N, int A[]) {
    for(int i = 0; i < N; i++) {
        if(i >= 1) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
}

void swap(int a[], int n1, int n2) {
    int temp = a[n1];
    a[n1] = a[n2];
    a[n2] = temp;
}

int main(){
    int n,count=0;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        int minj=i;
        for(int j =i;j<n;j++){
            if(a[minj]>a[j]){
                minj=j;
            }
        }
        if(minj != i){
            swap(a,minj,i);
            count++;
        }
    }
    trace(n,a);
    cout << count << endl;
}
