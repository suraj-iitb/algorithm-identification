#include<iostream>
using namespace std;

void trace(int A[], int N){
    int i;
    for(i=0; i<N; i++){
        if(i>0) cout<<" ";
        cout<<A[i];
    }
    cout<<"\n";
}

int sellectionSort(int A[], int N){
    int i, j, minj, tmp, swp_num=0, flag=0;
    for(i=0; i<N; i++){
        minj = i;
        for(j=i; j<N; j++){
            if(A[j] < A[minj]){
                minj = j;
                flag=1;
            }
        }
        if(flag==1){
            tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
            swp_num++;
        }
        flag=0;
    }
    return swp_num;
}
int main(){
    int num, i, ans;
    cin>>num;
    int arr[num];
    for(i=0; i<num; i++){
        cin>>arr[i];
    }
    ans = sellectionSort(arr, num);
    trace(arr, num);
    cout<<ans<<endl;
    return 0;
}
