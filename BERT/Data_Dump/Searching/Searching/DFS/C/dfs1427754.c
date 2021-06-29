#include<stdio.h>
#define NIL -1 /*???????????¶?§???????*/
#define MAX 100
#define WHITE 1
#define GRAY 2
#define BLACK 3

struct node{
 int list2[MAX];  
  int color;
  int number;
};


typedef struct node  Node;/*list1??????????????????????????????*/

void dfs(Node *);
void visit(Node *,int);

Node list1[MAX];          /*?????????1?§???????*/

int num,degree,time,d[MAX],f[MAX];
main()
{
  int i,j;
  scanf("%d",&num);
  for(i=1;i<=num;i++)
    {
      scanf("%d",&list1[i].number);
      scanf("%d",&degree);
      list1[i].list2[degree+1] = NIL;  /*???list???degree??????????????????NIL?????\??????*/
      if(degree != 0)
	{
      for(j=1;j<=degree;j++)
		{
	  scanf("%d",&list1[i].list2[j]);
		}
	}/*if degree ?????¨???*/
    }/*????????§?????????????????????*/

  dfs(list1);
  

  for(i=1;i<=num;i++)
    {
      printf("%d %d %d\n",i,d[i],f[i]);
    }
  return 0;
}

void dfs(Node* list1)
{
  int i,j;
  for(i=1;i<=num;i++)
    {
      list1[i].color = WHITE;
      time = 0;
    }

  for(j=1;j<=num;j++)
    {
      if(list1[j].color==WHITE) visit(list1,j);

    }
}

void visit(Node* list1, int j)
{
  int i;
  list1[j].color = GRAY;
  d[j] = ++time;
  for(i=1;i<=MAX;i++)
    {
      if(list1[j].list2[i]==NIL)break;
      else if(list1[list1[j].list2[i]].color == WHITE) visit(list1,list1[j].list2[i]);
    }
  
  list1[j].color = BLACK;
  f[j] = ++time;
    
  
}
