#include<stdio.h>
#define MAX 120
#define NIL -1

#define WHITE 1
#define GRAY 2
#define BLACK 3

struct node{
  int list2[MAX];
  int color;
  int number;
};
typedef struct node Node;

void enq(int);
int deq(void);
void bfss(Node*);

int Q[MAX],atama=1,tail=1,hozon;
Node list1[MAX];


int num,degree,time,d[MAX];
main()
{
  
  int i,j;
  scanf("%d",&num);
  for(i=1;i<=num;i++)
    {
      scanf("%d",&list1[i].number);/*list1は添字番号がそのまま値*/
      scanf("%d",&degree);
      list1[i].list2[degree+1] = NIL;

      if(degree != 0)
	{
	  for(j=1;j<=degree;j++)
	    {
	      scanf("%d",&list1[i].list2[j]);
	    }
	}/*ifとじ*/

    }/*これで情報は入った*/


  bfss(list1);

  for(i=1;i<=num;i++)
    {
      printf("%d %d",i,d[i]);
    
  printf("\n");
}
  return 0;
}

void bfss(Node* list1)
{
  int i,j;
  for(i=1;i<=num;i++)/*初期化*/
    {
      list1[i].color = WHITE;
      d[i] = NIL;
    }

  list1[atama].color = GRAY;
  d[atama] = 0;

  enq(list1[atama].number);/*これで一個モノが入ってatama=1,tail=2*/

while(Q[atama]!=Q[tail])
    {
      hozon = deq();

      for(i=1;i<=MAX;i++)/*degreeをあさる*/
	{
	  if(list1[list1[hozon].list2[i]].color == WHITE)/*vはuのdegreeの文字*/
	    {
	      list1[list1[hozon].list2[i]].color = GRAY;
	      d[list1[hozon].list2[i]] = d[hozon] + 1;
	      enq(list1[list1[hozon].list2[i]].number);

	    }
	}
      list1[hozon].color = BLACK;
    }


} 

void enq(int number)
{
  Q[tail] = number;
  tail+=1;
}

int deq(void)
{
  atama+=1;
  return Q[atama-1];
}
