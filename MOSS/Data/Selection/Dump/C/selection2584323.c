i,j,t,m,N,A[100];
main(){
    for(scanf("%d",&N);i<N;scanf("%d",&A[i++]));
    for(i=0;i<N-1;i++){
        for(j=m=i;j<N;j++){
            if(A[j]<A[m])m=j;
        }
        if(m!=i){
        A[i]^=A[m]^=A[i]^=A[m];
        t++;
        }
    }
    for(i=0;i<N;printf("%d%s",A[i],i==N-1?"\n":" "),i++);
    printf("%d\n",t);
}
