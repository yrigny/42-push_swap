#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	stack_a = NULL;
	if (argc < 2)
	{
		printf("No data to sort. Exit.\n");
		return (-1);
	}
	if (!parser(argv, &stack_a))
	{
		printf("Invalid list of data. Exit.\n");
		return (-1);
	}
	while (stack_a)
	{
		printf("%d %d\n", stack_a->data, stack_a->idx);
		stack_a = stack_a->next;
	}
	free_stack(&stack_a);
	// iterate argv, check data, create the stack a along the way
	// once meeting a wrong data, free the list and print Error
	// when stack a is ok, start to sort
	// sorter(stack_a); // return the push swap instructions list
	// print the push swap instructions list
	return (0);
}
