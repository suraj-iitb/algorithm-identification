//トランプを並び替えるときに自然で思いつきやすいアルゴリズムのひとつ
//✕
#include <iostream>
using namespace std;

void trace(int A[], int n){
    int i;
    for (i=0; i<n; i++){
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}
void insertion_sort(int A[], int n){ //n個の要素を含む0－オリジンの配列
    int v,i,j;
    for (i=1; i<n; i++){
        v = A[i];
        j = i-1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        trace(A, n);
    }
}

int main(){
    int A[100+1],n,i,j; cin >> n; 
    for (i=0; i<n; i++) cin >> A[i];

    trace(A, n);
    insertion_sort(A,n);
}
