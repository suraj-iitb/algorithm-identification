#include"stdio.h"
#include"stdlib.h"
struct num
{
  int n;
  struct num *next;
};
int main()
{
  int n;
  int q;
  struct num *S;
  int *T;
  struct num *p;
  int i;
  int m;
  int C=0;
  S=(struct num*)malloc(sizeof(struct num));
  S->next=NULL;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&m);
      for(p=S;p->next!=NULL;p=p->next)
        {
          if(p->next->n==m)break;
        }
      if(p->next==NULL)
        {
          p->next=(struct num*)malloc(sizeof(struct num));
          p->next->n=m;
          p->next->next=NULL;
        }
    }
  scanf("%d",&q);
  T=(int*)malloc(sizeof(int)*q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&T[i]);
    }
  for(p=S->next;p!=NULL;p=p->next)
    {
      for(i=0;i<q;i++)
        {
          if(p->n==T[i])
            {
              C++;
              break;
            }
        }
    }
  printf("%d\n",C);
}
