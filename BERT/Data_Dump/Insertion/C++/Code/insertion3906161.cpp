# include<iostream>
using namespace std;
void insertion_sort(int A[], int n){
    for(int i=1; i<n; i++){
        for(int j=0; j<n-1; j++) cout << A[j] <<" ";
        cout << A[n-1] <<"\n";
        int v = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
            A[j+1] = v;
        }
    }
}
int main(){
    int A[1000];
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    insertion_sort(A,n);
    for(int j=0; j<n-1; j++) cout << A[j] <<" ";
    cout << A[n-1] <<"\n";
    return 0;
}
