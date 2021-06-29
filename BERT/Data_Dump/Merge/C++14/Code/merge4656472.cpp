#include <iostream>
#include <vector>
using namespace std;
int count = 0;

void merge(int A[],int left,int mid,int right){
    int n1,n2;
    n1 = mid - left;
    n2 = right - mid;
    int L[n1+1],R[n2+1];
    for(int i = 0; i <= n1-1; i++) L[i] = A[left+i];
    for(int i = 0; i <= n2-1; i++) R[i] = A[mid+i];
    L[n1] = 2000000000;
    R[n2] = 2000000000;
    int i = 0;
    int j = 0;
    for(int k = left ; k < right; k++){
        if(R[j] <= L[i]){
            A[k] = R[j];
            j++;
            count++;
        }else{
            A[k] = L[i];
            i++;
            count++;
        }
    }
    
}

void mergeSort(int A[], int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}



int main(){
    int A[600000];
    int n;
    cin >> n;
    for(int i=0; i < n; i++){
        cin >> A[i];
    }
    mergeSort(A,0,n);
    for(int i=0; i < n; i++){
        cout << A[i];
        if(i != n-1) cout << " ";
    }
    cout << endl;
    cout << count << endl;

    return 0;

}
