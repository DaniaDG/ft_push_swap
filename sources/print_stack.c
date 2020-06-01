#include "ft_push_swap.h"
#include "stdio.h"

void	print_stack(t_stack *a, t_stack *b)
{
	t_stack		*tmp;

	if (!a)
		printf("a = NULL\n");
	else
	{
		tmp = a;
		printf("%d (%s) i = %d\n", tmp->data, tmp->status == TRUE ? "true" : "false", tmp->index);
		tmp = tmp->down;
		while (tmp != a)
		{
			printf("%d (%s) i = %d\n", tmp->data, tmp->status == TRUE ? "true" : "false", tmp->index);
			tmp = tmp->down;
		}
		printf("--\n");
		printf("a\n");
	}
	if (!b)
		printf("\tb = NULL\n");
	else
	{
		tmp = b;
		printf("\t%d (%s) i = %d\n", tmp->data, tmp->status == TRUE ? "true" : "false", tmp->index);
		tmp = tmp->down;
		while (tmp != b)
		{
				printf("\t%d (%s) i = %d\n", tmp->data, tmp->status == TRUE ? "true" : "false", tmp->index);
				tmp = tmp->down;
		}
		printf("\t--\n");
		printf("\tb\n");
	}
	printf("\n");
}
