        #include<stdio.h>
        #define N 100

        int n,A[N][N],cp[N];

        void Breadth(int pl,int res)
        {
          int i;

          res++;
          cp[pl]=res;

          for(i=0; i<n; i++){

            if(A[pl][i]==1){
              if(cp[i]<=res && cp[i]>=0)continue;
              Breadth(i,res);
            }

          }
        }

        int main(void){
          int i,j,k,x,y;

          scanf("%d",&n);

          for(i=0; i<n; i++){

            for(j=0; j<n; j++){

              A[i][j]=0;

            }

          }
          for(i=0; i<n; i++){
            scanf("%d %d",&x,&k);
            x--;

            for(j=0; j<k; j++){
              scanf("%d",&y);
              y--;
              A[x][y]=1;
            }
          }
          for(i=0; i<n; i++){
            cp[i]=-1;
          }
          Breadth(0,-1);
          for(i=0; i<n; i++){
            printf("%d %d\n",i+1,cp[i]);
          }
          return 0;
        }

