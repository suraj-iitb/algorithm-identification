#include <stdio.h>


#define N 101
#define white 2
#define gray 3
#define black 4
int A[N][N],t[N],f[N],color[N];
void dfs(int);
void dfs_init(void);
int a=0,b=0,c=0,v=0,time=0;

int main(){
  int c=0,d=0;
  scanf("%d",&a);
  
  for(int i=0;i<a;i++){  
     for(int j=0;j<a;j++){
        A[i][j]=0;
     }
  }  
  
  for(int i=0;i<a;i++){
     scanf("%d%d",&b,&d);
     
     for(int j=0;j<d;j++){
        scanf("%d",&c);
        A[b-1][c-1] = 1;
     }
  }

//printf("\n");

  dfs_init();
  
  
  
  
  for(int i=0;i<a;i++){
        printf("%d %d %d",i+1,t[i],f[i]);
     printf("\n");
  }
  
  
  
  
 /* 
  for(int i=0;i<a;i++){
     
     for(int j=0;j<a;j++){
        printf("%d",A[i][j]);
        if(j<a-1)printf(" ");
     }
     printf("\n");
  }
*/ 

   
return 0;
}



void dfs(int x){
   
   color[x] = gray;
   t[x] = ++time;
   
   for(int i=0;i<a;i++){
      
      if( A[x][i] == 1 && color[i] ==white) dfs(i);
   }
   
   color[x] = black;
   f[x] = ++time;

}
void dfs_init(void){

   for(int i =0;i<a;i++) color[i] = white;
   for(int i =0;i<a;i++)if(color[i] == white) dfs(i);

}
