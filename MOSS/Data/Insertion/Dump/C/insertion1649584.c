int main()
{
    int i,j,k,N,m;
    int A[100];
    
    scanf("%d",&N);
    for (i=0; i<N; i++)scanf("%d",&A[i]);
       
    for(i=1;i<N+1;i++){
        m=A[i];
        j=i-1;

        for(k=0;k<N;k++){
            printf("%d",A[k]);
            if(k<N-1)printf(" ");
            else printf("\n");
            }
     
        while(A[j]>m){
            A[j+1]=A[j];
            j--;
            A[j+1]=m;
            }
        }
    
 return 0;
}
