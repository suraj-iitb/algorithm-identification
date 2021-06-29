#include<stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs(void);
void visit(int);

int A[1000][1000],time,d[1000],f[1000],color[1000],S[1000],top=1,tail=1,n;



int main(){

  int i,j,u,k,v;

  scanf("%d",&n);

  for(i=0;i<n;i++){

    A[i][i]=0;

  }

  for(i=1;i<=n;i++){
  
    scanf("%d%d",&u,&k);

    for(j=1;j<=k;j++){

      scanf("%d",&v);
      
      A[u][v]=1;



    }
  }
  /* for(i=1;i<=n;i++){
    for(j=1;j<n;j++){
      


      
      printf("%d ",A[i][j]);
      
    }
    printf("%d",A[i][j]);
    printf("\n");
    }*/
  
  dfs();

  for(i=1;i<=n;i++){

    printf("%d %d %d\n",i,d[i],f[i]);

  }


  /*for(i=0;i<n;i++){
    for(j=0;j<n-1;j++){

      
       printf("%d ",A[i][j]);

    }
    printf("%d",A[i][j]);
    printf("\n");
    }*/ 

  return 0;
}

void dfs(){

  int i;

  //printf("wa-i\n");
  
  for(i=1;i<=n;i++){

    color[i]=WHITE;
  }

  //printf("wa-i2\n");

  time =0;

  for(i=1;i<=n;i++){

    if(color[i]==WHITE){
      visit(i);
      // break;
    }
  } 

}

void visit(int r){

  int u,v,i,count=0;

  // printf("wa-i3\n");
  tail++; 
  S[tail-1]=r; 
  color[r] = GRAY;
  d[r]=++time;

  // printf("%d\n",r);
  // printf("%d\n",tail);
  //printf("%d\n",S[tail-1]);
  
  //printf("wa-i4\n");

  //printf("wa-i\n");

  while(top!=tail){

    //printf("wa-i100\n");
    
    u = S[tail-1];
    v=-1;

    // printf("color:%d\n",color[u]);

    

    //printf("wa-i101\n");

    count=0;
    
    for(i=1;i<=n;i++){  

      //printf("wa-i1\n");
      //if(u==0)break;
      if(A[u][i]==1&&color[i]==WHITE){
	v=i;
	count++;
      }
      
      //printf("i:%d u:%d,v:%d,color:%d\n",i,u,v,color[v]);
      //printf("A:%d\n",A[u][i]);

      
      //printf("wa-i5\n");

      if(count==1)break;
    }
    

    if(v != -1){

      // printf("wa-i2\n");
	      
      if(color[v]==WHITE){
	tail++;
	S[tail-1]=v;
	//tail++;
	color[v]=GRAY;
	d[v] = ++time;
      }
      
    }
    else{

      //printf("wa-i3\n");
      tail--;
      color[u] = BLACK;
      f[u]=++time;

    }
    // printf("tail:%d top:%d,%d u:%d %d\n ",tail,top,S[tail-1],S[top],u,v);
    
  }

  
}
