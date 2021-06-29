#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 110000

int* fget_array(int *arr, int size, char *line) {
  char *tmpbuf = line;
  int i;
  for(i = 0; i < size; i++) {
    char *tmp = strtok(tmpbuf, " ");
    arr[i] = strtol(tmp, NULL, 10);
    tmpbuf = NULL;
  }
  return arr;
}
#define HTABLE_SIZE 65536
#define KEY_MASK 65535

int get_key(int num) {
  return num & KEY_MASK;
}

struct list {
  struct list *next;
  int num;
};

struct list *create_htable(int size) {
  struct list *htable = malloc(sizeof(struct list)*size);
  int i;
  for(i = 0; i < size; i++) {
    htable[i].next = &htable[i];
  }
  return htable;
}

struct list *find(struct list *htable, int num) {
  struct list *head = &htable[get_key(num)];
  struct list *tmp;
  for(tmp = head->next; tmp != head; tmp = tmp->next) {
    if(tmp->num == num) return tmp;
  }
  return NULL;
}

void insert(struct list *htable, int num) {
  int key = get_key(num);
  struct list *head = &htable[key];
  struct list *elem = find(htable, num);
  if(elem) return;
  // or create
  elem = malloc(sizeof(struct list));
  elem->next = head->next;
  head->next = elem;
  elem->num = num;
  return;
}

int main(void) {
  FILE *fp = stdin;
  char line[BUF_SIZE];
  int i, j;

  if(!fgets(line, BUF_SIZE, fp)) return 0;
  int num;
  sscanf(line, "%d", &num);
  struct list *htable = create_htable(HTABLE_SIZE);

  if(!fgets(line, BUF_SIZE, fp)) return 0;
  char *tmpbuf = line;
  for(i = 0; i < num; i++) {
    char *tmp = strtok(tmpbuf, " ");
    int n = strtol(tmp, NULL, 10);
    insert(htable, n);
    tmpbuf = NULL;
  }

  int queries;
  if(!fgets(line, BUF_SIZE, fp)) return 0;
  sscanf(line, "%d", &queries);


  if(!fgets(line, BUF_SIZE, fp)) return 0;
  tmpbuf = line;
  int cnt = 0;
  for(i = 0; i < queries; i++) {
    char *tmp = strtok(tmpbuf, " ");
    int q = strtol(tmp, NULL, 10);
    if(find(htable, q)) {
      cnt++;
    }
    tmpbuf = NULL;
  }

  printf("%d\n", cnt);
  return 0;
}
