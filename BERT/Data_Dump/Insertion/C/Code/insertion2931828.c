#include<stdio.h>
main(){
        int i,j,key,N;
            
            scanf("%d ",&N);
                int a[N];
                    for(i=0;i<N;i++){
                                scanf("%d",&a[i]);
                                    }
                        
                        for(j=1;j<N;j++){
                              for(i=0;i<N;i++){
                                  printf("%d",a[i]);
                                  if(i+1!=N){
                                      printf(" ");
                                  }
                              }
                              printf("\n");
                              key = a[j];
                              i=j-1;
                              while(i>=0 && a[i]>key){
                                  a[i+1]=a[i];
                                  i--;
                              }

                              a[i+1]=key;
                        }
                            
                        for(i=0;i<N;i++){
                            printf("%d",a[i]);
                            if(i+1!=N){
                                printf(" ");
                            }
                        }
                        printf("\n");
}

