#include<iostream>
using namespace std;

void trace(int A[], int N){
    int i;
    for(i=0; i<N; i++){
        if(i>0){
            cout<<" ";
        }
        cout<<A[i];
    }
    cout<<"\n";
}
int main(){
    int num, i, j, tmp, change_num=0;
    cin>>num;
    int arr[100];
    for(i=0; i<num; i++){
        cin>>arr[i];
    }
    for(i=0; i<num; i++){
        for(j=1; j<num-i; j++){
            if(arr[num-j] < arr[num-j-1]) {
                tmp = arr[num-j];
                arr[num-j] = arr[num-j-1];
                arr[num-j-1] = tmp;
                change_num++;
            }
        }
    }
    trace(arr, num);
    cout<<change_num<<endl;
    return 0;
}
