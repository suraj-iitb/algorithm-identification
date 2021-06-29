#include "stdio.h"
#include "iostream"

using namespace std;

int main()
{
        int n,key,j;
        int arr[100];

        cin >> n;

        for(int i=0;i<n;i++){
                cin >> arr[i];
        }
        for(int i=0;i<n;i++){
            if(i == n-1){
                printf("%d\n",arr[i]);
            }
	    else{
            	printf("%d ",arr[i]);
	    }
        }

        for(int i=1;i<n;i++){
                key = arr[i];
                j = i - 1;
                while(j >= 0 && arr[j] > key){
                        arr[j+1] = arr[j];
                        j--;
                }
                arr[j+1] = key;

                for(int t=0;t<n;t++){
                    if(t == n-1){
                        printf("%d\n",arr[t]);
                    }
		    else{
                    	printf("%d ",arr[t]);
		    }
                }
        }

        return 0;
}

