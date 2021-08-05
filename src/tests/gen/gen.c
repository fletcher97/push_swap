#include <stdlib.h>
#include <stdio.h>

static short
check(int *l, int p)
{
	for (int i = 0; i < p; i++)
		if (l[i] == l[p])
			return 0;
	return 1;
}

static void
gen_list(int c, int curr, int *l)
{
	if (curr == c)
	{
		for (int i = 0; i < c; i++)
		{
			printf("%d ", l[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < c; i++)
	{
		l[curr] = i;
		if (check(l, curr))
			gen_list(c, curr + 1, l);
	}
}

int
main(int argc, char *argv[])
{
	int count = 5;
	if (argc > 1)
		count = atoi(argv[1]);
	int *list = malloc(count * sizeof(int));
	gen_list(count, 0, list);
	free(list);
	return 0;
}
