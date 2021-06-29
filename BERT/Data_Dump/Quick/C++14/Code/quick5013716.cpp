#include<iostream>
#include<string>
using namespace std;
#define MAX 100000
#define SENTINEL 2000000000


struct Card{
    char mark;
    int value;
};


int partition(struct Card A[],int p,int r){
    int i,j;
    struct Card x;
    x = A[r];
    i = p-1;
    for(j=p;j<r;j++){
        if(A[j].value <= x.value){
            i = i+1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}


void quicksort(struct Card A[],int p,int r){
    if(p<r){
        int q=partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}

struct Card L[MAX/2+2],R[MAX/2+2];

void merge(struct Card A[],int left,int mid,int right){
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i=0;i<n1;i++)L[i] = A[left + i];
    for(int i=0;i<n2;i++)R[i] = A[mid + i];
    L[n1].value = R[n2].value = SENTINEL;
    int i=0;
    int j = 0;
    for(int k=left;k<right;k++){
        if(L[i].value <= R[j].value){
            A[k] = L[i];
            i = i + 1;
        }else{
            A[k] = R[j];
            j = j+1;
        }
    }
}

void mergeSort(struct Card A[],int left,int right){
    if(left + 1 < right){
        int mid = (left + right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}

int main(){
    int n,i,v;
    struct Card A[MAX],B[MAX];
    char m[10];
    int stable = 1;

    cin >> n;
    for(i=0;i<n;i++){
        cin >> m[0] >> v;
        A[i].mark = B[i].mark = m[0];
        A[i].value = B[i].value = v;
    }

    mergeSort(A,0,n);
    quicksort(B,0,n-1);

    for(i = 0;i<n;i++){
        if(A[i].mark != B[i].mark)stable = 0;
    }

    if(stable == 1)cout << "Stable" << endl;
    else cout << "Not stable" << endl;
    for(i=0;i<n;i++){
        cout << B[i].mark <<" "<< B[i].value << endl;
    }
    return 0;

}
