#include <stdio.h>
#include <stdlib.h>

typedef struct _elem {
  struct _elem *next;
  int data;
} elem;

elem head = { &head, -1 };

void insert(int data) {
  elem *new;
  new = (elem *)malloc(sizeof(elem));

  new->data = data;
  new->next = head.next;
  head.next = new;
}

int search(int data) {
  elem *p;
  p = head.next;

  head.data = data;

  while(p->data != data)
    p = p->next;

  return p != &head;
}

int main() {
  int n, q, i, tmp, cnt;
  cnt = 0;

  scanf("%d", &n);
  for(i = 0;i < n;i++) {
    scanf("%d", &tmp);
    insert(tmp);
  }

  scanf("%d", &q);
  for(i = 0;i < q;i++) {
    scanf("%d", &tmp);
    if(search(tmp))
      cnt++;
  }

  printf("%d\n", cnt);

  return 0;
}

