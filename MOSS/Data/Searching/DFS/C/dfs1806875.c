#include<stdio.h>


#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, M[N][N];
int color[N],d[N],f[N],tt;
/* id ha chouten bangou */
/* d ha sono chouten no hakken jikoku */
/* f ha sono chouten no kanryou jikoku */

/* saiki kannsuu ni yoru fukasa_yuusen_tansaku */
/* u ha chouten no bangou*/
void dfs_visit(int u)
{
  int v;
  color[u] = GRAY; /* houmon siita node GRAY ni suru */
  d[u] = ++tt; /* saisho no houmon */   /* jikoku wo 1 tuika */
  for (v = 0; v < n; v++)
    {
      if (M[u][v] == 0) continue; /* u gyou j retsu ni chouten ga nakattara for loop wo nukekru */
      if (color[v] == WHITE)
        {
          dfs_visit(v);/* saiki kannsuu wo yobu */
        }
    }
  color[u] = BLACK; /* u no rinestsu ni mihoumon(WHITE)ga nai node houmon_kanryou(BLACK)to suru */
  f[u] = ++tt;
}

  /* iro wo shokika tumari chouten wo white ni suru */
  /* mihoumon no u wo siten tosite fukasa yuusen tansaku */
  /* chouten_bangou , hakkenn_jikoku f, kannryou jikoku d, wo print */
void dfs()
{
 int u;
  /* syokika */
  for (u = 0; u < n; u++) color[u] = WHITE;
  tt = 0;

  /* u ha chouten no bangou*/
  for (u = 0; u < n;u++)
    {
      /* mihoumon no u wo shiten tosite fukasa yuusen tansaku */
      if (color[u] == WHITE) dfs_visit(u);
   }
  /* WHITE mihoumon */
  /* GRAY genzai houmon chuu mataha houmonsita chouten */
  /* BLACK houmon ga kanryou sita chouten */


  /* chouten no bangou, hakkenn_jikoku , kanryou_jikoku wo printout */
  for ( u = 0; u < n; u++)
    {
      printf("%d %d %d\n", u +1, d[u],f[u]);
    }
}


  
  int main ()
{
int u,v,k,i,j;
  scanf("%d",&n);/* chouten no kazu wo toru */
  /* rinsetsu gyouretsu wo shokika */
  for(i = 0; i < n; i++)
      {
        for (j = 0; j < n; j++)
          {
            M[i][j] = 0;
          }
      }
  /* rinsetsu gyouretsu ni atai wo ireru */
  for ( i = 0; i < n; i++)
    {
      scanf("%d %d",&u,&k);
        /* u ha chouten no bangou*/
        /* k ha syutu_ji_suu. tumamri rinsetsu suru chouten no kazu */
        u--; /* 0 orign no tame 1 hiku */
      for (j = 0; j < k; j++)
        {
          scanf("%d",&v);
          v--;/* 0 orign no tame 1 hiku */
          M[u][v] = 1;
        }
    }

  dfs();
  /* kansuu wo yobu*/
  /* iro wo shokika tumari chouten wo white ni suru */
  /* mihoumon no u wo siten tosite fukasa yuusen tansaku */
  /* chouten_bangou , hakkenn_jikoku f, kannryou jikoku d, wo print */
return 0;
}
