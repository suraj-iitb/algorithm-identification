#include <iostream>
using namespace std;
struct CARD{
    char mark;
    int num;
};
int partition(struct CARD card[],int n,int p,int r){
    int i,j;
    struct CARD t,x;
    x = card[r];
    i = p-1;
    for(j=p;j<r;j++){
        if(card[j].num <= x.num){
            i++;
            t=card[j]; card[j]=card[i]; card[i]=t;
        }
    }
    t=card[j]; card[j]=card[i+1]; card[i+1]=t;
    return i+1;
}
void quicksort(struct CARD card[],int n,int p,int r){
    int q;
    if(p < r){
        q = partition(card,n,p,r);
        quicksort(card,n,p,q-1);
        quicksort(card,n,q+1,r);
    }
}
struct CARD L[100000],R[100000];
void merge(struct CARD card[],int n,int left,int mid,int right){
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i=0;i<n1;i++){ L[i] = card[left+i];}
    for(int i=0;i<n2;i++){ R[i] = card[mid+i];}
    L[n1].num=R[n2].num=1000000000;
    int i=0;int j=0;
    for(int k=left;k<right;k++){
        if(L[i].num<=R[j].num){
            card[k]=L[i];
            i++;
        }else{
            card[k]=R[j];
            j++;
        }
    }
}
void mergesort(struct CARD card[],int n,int left,int right){
    if(left+1<right){
        int mid = (left+right)/2;
        mergesort(card,n,left,mid);
        mergesort(card,n,mid,right);
        merge(card,n,left,mid,right);
    }

}
int main(){
    int n;
    cin >> n;
    CARD A[100000];
    CARD B[100000];
    for(int i=0;i<n;i++){
        cin >> A[i].mark >> A[i].num;
        B[i] = A[i];
    }


    quicksort(A,n,0,n-1);
    mergesort(B,n,0,n);
    
    int stable = 1; 
    for(int i=0;i<n;i++){
        if(A[i].mark!=B[i].mark) stable = 0;
    }

    if(!stable){
        cout << "Not stable" << endl;
    }else{
        cout << "Stable" << endl;
    }

    for(int i=0;i<n;i++){
        cout << A[i].mark << " " << A[i].num << endl;
    }

    return 0;
}
