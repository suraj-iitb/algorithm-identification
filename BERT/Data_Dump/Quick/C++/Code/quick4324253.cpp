#include<bits/stdc++.h>
using namespace std;

struct card{
    public: char c; int x;
};

void merge(card *A, int left, int mid, int right){
    int n1=mid - left;
    int n2 = right - mid;
    int i,j,k;
    card L[1000000], R[1000000];
    for(i=0;i<n1;i++){
        L[i].c = A[left+i].c;
        L[i].x = A[left+i].x;
    }
    for(i=0;i<n2;i++){
        R[i].c = A[mid+i].c;
        R[i].x = A[mid+i].x;
    }
    L[n1].x = 100000000;
    R[n2].x = 100000000;

    i=0;
    j=0;
    for(k=left;k<right;k++){
        if(L[i].x<=R[j].x){
            A[k]=L[i];
            i++;
        }

        else{
            A[k]=R[j];
            j++;
        }
    }
}

void mergesort(card *A, int left, int right){
    int mid = (left+right)/2;
    if(left+1<right){
        mergesort(A, left, mid);
        mergesort(A, mid, right);
        merge(A, left, mid ,right);
    }
}



int partition(int *A, int p, int r){
    int i, j;
    int x = A[r];
    i=p-1;
    for(j=p;j<r;j++){
        if(A[j]<=x){
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

int partition_card(card *A, int p, int r){
    int i, j;
    int x = A[r].x;
    i=p-1;
    for(j=p;j<r;j++){
        if(A[j].x<=x){
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

void quicksort(int *A, int p, int r){
    if(p<r){
        int q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}

void quicksort_card(card *A, int p, int r){
    if(p<r){
        int q = partition_card(A, p, r);
        quicksort_card(A, p, q-1);
        quicksort_card(A, q+1, r);
    }
}

int main(){
    int n;
  	int t;
  	char tc;
    card A[1000000];
  	card B[1000000];
    scanf("%d", &n);
    for(int k=0;k<n;k++){
        scanf("%s %d", &tc, &t);
        B[k].c = A[k].c = tc;
        B[k].x = A[k].x = t;
    }


    quicksort_card(A, 0, n-1);
    mergesort(B, 0, n);
    int k=1;
    for(int j=0;j<n;j++){
        if(A[j].c!=B[j].c){
            cout<<"Not stable"<<endl;
            k=0;
            break;
        };
        //cout<<A[j].c<<" "<<A[j].x<<endl;
    }

    if(k) cout<<"Stable"<<endl;

    for(int j=0;j<n;j++){
        if(A[j].c!=B[j].c) k=0;
        cout<<A[j].c<<" "<<A[j].x<<endl;
        //cout<<B[j].c<<" "<<B[j].x<<endl;
      
    }

    return 0;
}

