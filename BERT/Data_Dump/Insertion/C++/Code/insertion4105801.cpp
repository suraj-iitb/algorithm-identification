#include <iostream>
using namespace std;
int insertionSort(int n,int N[]);
int main(void){
    int n;//需要排序的数字个数
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }//读入n个数字
    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i<n-1) cout<<" ";
    }
    cout<<endl;
    insertionSort(n,arr);
    return 0;
}
int insertionSort(int n,int N[]){
    //从小到大
    for(int i=1;i<n;i++){
        int key=N[i];
        int j=i-1;
        while(j>=0&&key<N[j]){
            N[j+1]=N[j];
            j--;
        }
        N[j+1]=key;
        for(int i=0;i<n;i++)
            {
                cout<<N[i];
                if(i<n-1) cout<<" ";
            }
        cout<<endl;
    }
}
