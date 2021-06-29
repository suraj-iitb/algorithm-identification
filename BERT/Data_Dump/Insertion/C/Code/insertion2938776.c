#include<stdio.h>
#include<stdlib.h>

int main(void){
    int i, N, V, j, k;
    int *In;

    scanf("%d",&N);
    In = (int*)malloc(sizeof(int)*N);
      for(k=0 ; k<N ; k++){
            scanf("%d",&In[k]);
        }
  printf("%d",In[0]);
             for(k=1 ; k<N ; k++){
            printf(" %d",In[k]);
        }
        printf("\n");


    for(i=1 ; i<N ; i++){
        V=In[i];
        j=i-1;
        while(j>=0 && In[j]>V){
            In[j+1] = In[j];
            j--;
            In[j+1]=V;
        }
        printf("%d",In[0]);
        for(k=1 ; k<N ; k++){
            printf(" %d",In[k]);
        }
        printf("\n");
    }
    free(In);
    return 0;
}
