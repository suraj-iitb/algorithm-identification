#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

#define rep(i,n,m) for(int i=n; i<=m; i++)
#define per(i,n,m) for(int i=n; i>=m; i--)
#define printi(x) printf("%d ", x)
#define printiln(x) printf("%d\n", x)
#define printiarray(a,n) for(int i=0; i<n-1; i++){printf("%d ", a[i]);} printf("%d\n", a[n-1])
#define scani(x) scanf("%d", &x)
#define scaniarray(a,n) for(int i=0; i<n; i++){scanf("%d", &a[i]);}
#define scans(str) scanf("%s",str)
#define scanc(ch) scanf("%c", &ch)

const int NMax = 500000;
int B[NMax];
int count = 0;
void merge(int *A, int left, int mid, int right);
void mergeSort(int *A, int left, int right);

int main() {
    int n;
    scani(n);
    scaniarray(B,n);

    mergeSort(B,0,n);

    printiarray(B,n);
    printiln(count);


    return 0;
}

void merge(int *A, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1];
    int R[n2];
    rep(i,0,n1-1) {
        L[i] = A[left+i];
    }
    rep(i,0,n2-1) {
        R[i] = A[mid + i];

    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int i = 0;
    int j = 0;
    rep(k,left,right-1) {
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
            count++;

        }
        else {
            A[k] = R[j];
            j++;
            count++;

        }
    }
}


void mergeSort(int *A, int left, int right) {
    if(left+1 < right){
        int mid = (left + right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);

    }
}

