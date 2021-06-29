#include <iostream>
using namespace std;
#define MAX 100000
#define SENTINEL 2000000000;

class Card{
public:
    int num;
    char mark;
    Card& operator=(Card& c){
        (*this).num = c.num;
        (*this).mark = c.mark;
        return (*this);
    }
};

istream& operator>>(istream& is, Card& c){
    is >> c.mark >> c.num;
    return is;
};

void merge(Card A[],int n,int left,int mid,int right){
    int n1 = mid - left;
    int n2 = right - mid;
    Card L[n],R[n];

    for(int i = 0; i < n1; i++){
        L[i] = A[left+i];
    }
    for(int i =0; i < n2; i++){
        R[i] = A[mid+i];
    }
    L[n1].num = R[n2].num = SENTINEL;
    int i = 0, j = 0;
    for(int k = left;k < right; k++){
        if(L[i].num<=R[j].num){
            A[k] = L[i++];
        }
        else{
            A[k] =R[j++];
        }
    }
}

void mergeSort(Card A[], int n, int left, int right){
    if(left+1 < right){
        int mid = (left + right)/2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}


int partation(Card A[],int n, int p,int r){
    int i,j;
    Card x,y;
    i = p-1;
    x = A[r];
    for(j = p; j < r; j++){
        if(A[j].num <= x.num){
            i++;
            y = A[i];
            A[i] = A[j];
            A[j] = y;
        }
    }
    y = A[i+1];
    A[i+1] = A[r];
    A[r] = y;
    return i+1;
}

void quickSort(Card A[],int n,int p,int r){
    if(p <= r){
        int q = partation(A,n,p,r);
        quickSort(A,n,p,q-1);
        quickSort(A,n,q+1,r);
    }
}

int main(){
    int n;
    cin >> n;
    Card a[MAX],b[MAX];
    for(int i = 0; i < n; i++){
        cin >> a[i];     
    }
    for(int i =0; i < n; i++){
        b[i] = a[i];
    }
    quickSort(a,n,0,n-1);
    mergeSort(b,n,0,n);

    int flag = 1;
    for(int i =0; i < n; i++){
        if(a[i].mark != b[i].mark){
            flag = 0;
            break;
        }
    }
    if(flag == 1){
        cout << "Stable" << '\n';
    }
    else{
        cout << "Not stable" << '\n';
    }
    for(int i =0; i < n; i++){
        cout << a[i].mark << " " << a[i].num << '\n';
    }
    return 0;
}
