#include<iostream>
using namespace std;

int count=0; 
int BubbleSort(int A[],int N){
   
    bool flag=1;
    while(flag){
        flag=0;
        for(int j=N-1;j>=1;j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                count++;
                flag=1;
            }
        }
    }
    return count;
}

int main(){
    int n=0;
    cin >> n;
    int array[n];
    for(int i=0;i<n;i++){
        cin >> array[i];
    }
    int i = BubbleSort(array,n);
    for(int i=0;i<n-1;i++){
        cout << array[i] << " ";
    }
    cout << array[n-1] << endl << count << endl;
    return 0;
     
}
