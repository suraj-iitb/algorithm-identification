#include "stdio.h"
#include "iostream"

using namespace std;

int bubble_sort(int *arr,int n)
{
        int i,j,num=0;

        for(i=0;i<n;i++){
                for(j=n-1;j>0;j--){
                        if(arr[j-1] > arr[j]){
                                swap(arr[j-1],arr[j]);
                                num++;
                        }
                }
        }

        return num;
}

int main()
{
        int n,num;

        cin >> n;

        int arr[n];

        for(int i=0;i<n;i++){
                cin >> arr[i];
        }

        num = bubble_sort(arr,n);

        for(int i=0;i<n;i++){
                if(i != n-1){
                        printf("%d ",arr[i]);
                }
                else{
                        printf("%d\n",arr[i]);
                }
        }

        cout << num << endl;


        return 0;
}
