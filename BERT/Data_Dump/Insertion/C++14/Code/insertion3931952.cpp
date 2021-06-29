#include<bits/stdc++.h>
int x[100];
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
        scanf("%d",&x[i]);




    int i, key, j;
    for(int k = 0;k < n; k++){
		if(k != n-1){
			printf("%d ",x[k]);
		}else{
			printf("%d\n",x[k]);
		}
	}

    for (i = 1; i < n; i++)
    {
        key = x[i];
        j = i - 1;

        while (j >= 0 && x[j] > key)
        {
            x[j + 1] = x[j];
            j = j - 1;

        }
        x[j + 1] = key;
        //printf(" \n");
        /*
        for(int i=0; i<n; i++)
            printf("%d ",x[i]);*/
        for(int k = 0;k < n; k++){
		if(k != n-1){
			printf("%d ",x[k]);
		}else{
			printf("%d\n",x[k]);
		}
	}

    }

    return 0;
}

