#include<iostream>
#include<algorithm>
using namespace std;
struct Card{
    char a;
    int b;
};
bool compare_as_ints(Card i, Card j){ // stable_sort()のため
    return (i.b<j.b);
}
int partition(Card A[], int p, int r){
    Card x=A[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++){
        if(A[j].b<=x.b){
            i+=1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}
void QuickSort(Card A[], int p, int r){
    if(p<r){
        int q=partition(A, p, r);
        QuickSort(A, p, q-1);
        QuickSort(A, q+1, r);
    }

}
int main(){
    int n;
    cin>>n;

    Card A[100000], B[100000];
    for(int i=0;i<n;i++){
        cin>>A[i].a>>A[i].b;
        B[i]=A[i];
    }
    QuickSort(A, 0, n-1);
    stable_sort(B, B+n, compare_as_ints);
    bool f=true;
    for(int i=0;i<n;i++){
        if(!(A[i].a==B[i].a&& A[i].b==B[i].b)){
            f=false;
            break;
        }
    }
    if(f){
        cout<<"Stable"<<endl;
    }else{
        cout<<"Not stable"<<endl;
    }
    for(int i=0;i<n;i++){
        cout<<A[i].a<<' '<<A[i].b<<endl;
    }
}