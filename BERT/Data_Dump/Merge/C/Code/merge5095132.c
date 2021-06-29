#include<stdio.h>

void mergesort(int a[],int,int);
int n,c=0;

int main(){
    int i,j,a[1000000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    mergesort(a,0,n-1);
    
    for(j=0;j<n;j++){
        printf("%d",a[j]);
        if(j<n-1){
        printf(" ");
        }
    }
    printf("\n");
    printf("%d\n",c);
    return 0;
}

void mergesort(int a[],int left,int right){
    int i, j, k, mid;
    int s[n];
    if (left < right) {
        mid = (left + right)/2;
        mergesort(a, left, mid);  
        mergesort(a, mid+1, right);  
        for (i = mid; i >= left; i--){
            s[i] = a[i];
        } 
        for (j = mid+1; j <= right; j++){
            s[right-(j-(mid+1))] = a[j];
        }
        i = left; 
        j = right;
        for (k = left; k <= right; k++){
        if(s[i] < s[j]){
            a[k] = s[i++];
            c++;
        }
        else{
            a[k] = s[j--];
            c++;
        }
        }
    }
}
