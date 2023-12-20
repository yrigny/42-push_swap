#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*tmp;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!parser(argc, argv, &stack_a))
		return (0 * printf("Error\n"));
	tmp = stack_a;
	while (tmp)
	{
		printf("%d %d\n", tmp->data, tmp->idx);
		tmp = tmp->next;
	}
	free_stack(&stack_a);
	// iterate argv, check data, create the stack a along the way
	// once meeting a wrong data, free the list and print Error
	// when stack a is ok, start to sort
	// sorter(stack_a); // return the push swap instructions list
	// print the push swap instructions list
	return (0);
}
