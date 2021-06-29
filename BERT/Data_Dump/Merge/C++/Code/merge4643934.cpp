#include <bits/stdc++.h>
using namespace std;
const int MAX=1000000001;

int merge_sort(int A[],int left,int right){
    if(left+1==right)return 0;
    int midth=(left+right)/2;
    int ss=merge_sort(A,left,midth)+merge_sort(A,midth,right);
    int B[midth-left+1],C[right-midth+1];
    B[midth-left]=MAX;
    C[right-midth]=MAX;
    for(int i=0;i<midth-left;i++){
        B[i]=A[left+i];
    }
    for(int i=0;i<right-midth;i++){
        C[i]=A[midth+i];
    }
    int dd=0,ff=0,i=left;
    while(dd!=midth-left||ff!=right-midth){
        if(B[dd]>C[ff]){
            A[i]=C[ff];
            ff++;
        }
        else{A[i]=B[dd];dd++;}
        i++;
        ss++;
    }
    return ss;
}

int main(){
    int n;
    scanf("%d",&n);
    int A[n+1];
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    int k=merge_sort(A,0,n);
    for(int i=0;i<n-1;i++){
        printf("%d ",A[i]);
    }
    printf("%d\n",A[n-1]);
    printf("%d\n",k);
}

