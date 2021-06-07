#include <stdio.h>

void visit(int,int);

int d[100] = {};
int tm = 0;
int inpo[100][100];
int f[100] = {};

void visit(int i, int x)
{
  int j;

        tm++;
        d[i] = tm;
        for(j = 0; j < x; j++)
          {
            if(d[j] == 0 && inpo[i][j] != 0) visit(j,x);
          }
        tm++;
        f[i] = tm;
}



int main () {

  int x;
  int i,j,u,k,y;

        scanf("%d",&x);

        for(i = 0; i < x; i++)
          {
            scanf("%d %d",&u,&k);
                for(j = 0; j < k; j++)
                  {
                    scanf("%d",&y);
                    inpo[u-1][y-1] = 1;
                  }
          }

        for(i = 0; i < x; i++)
          {
            if(d[i] == 0) visit(i,x);
          }

        for(i = 0; i < x; i++)
          {
            printf("%d %d %d\n",i+1,d[i],f[i]);
          }
        return 0;
}


