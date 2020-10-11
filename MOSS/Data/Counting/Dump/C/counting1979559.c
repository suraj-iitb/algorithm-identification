#include <stdio.h>          // printf(), getline()
#include <stdlib.h>         // exit(), malloc(), free(), strtol()
#include <string.h>         // memset()
#include <stdbool.h>
#include <errno.h>          // errno
#ifdef linux
 #include <error.h>         // error()
#endif

#define MAX_N 2000000
#define MAX_V 10000

const char NUL = '\0';
int lineno;
char* linebuff = NULL;
size_t linebuffsize = 0;

void
cleanup(int ecode)
{
	if (linebuff)
	{
		free(linebuff);
		linebuff = NULL;
		linebuffsize = 0;
	}

	exit(ecode);
}

bool
readline()
{
	errno = 0;
	if(getline(&linebuff, &linebuffsize, stdin) == -1) // read line
	{
		if(errno == 0)  // EOF?
			return false;

#ifdef linux
		error(0, errno, "Can't read line");
#else
		fprintf(stderr, "Can't read line\n");
#endif
		cleanup(1);
	}

	return true;
}

void
skip_sp(const char** p)
{
	while (**p == ' ')
		(*p)++;
}

int
main(int argc, char** argv)
{
	unsigned short *a, *b;
	int c[MAX_V + 1];
	char* nextp = NULL;
	int x;
	int n, i;

	readline();
	lineno = 1;
	const char* s = linebuff;
	n = strtol(s, &nextp, 10);
	s = nextp;

	a = malloc(sizeof(short) * n + 1);
	b = malloc(sizeof(short) * n + 1);
	memset(c, 0, sizeof(int) * MAX_V + 1);

	readline();
	s = linebuff;
	lineno++;

	int max = 0;
	for (i = 0; i < n; ++i)
	{
		skip_sp(&s);
		if (*s == NUL)
			cleanup(0);

		if (*s == '\n')
		{
			if (!readline())
				cleanup(0);

			lineno++;
			s = linebuff;
		}

		x = strtol(s, &nextp, 10);
		s = nextp;

		a[i + 1] = x;
		c[x]++;
		if (x > max)
			max = x;
	}

	for (i = 1; i <= max; ++i)
		c[i] = c[i] + c[i - 1];

	for (i = n; i >= 1; --i)
	{
		b[c[a[i]]] = a[i];
		c[a[i]]--;
	}

	for (i = 1; i <= n; ++i)
		printf("%d%c", b[i], (i != n) ? ' ' : '\n');

	free(a);
	free(b);
	return 0;
}
