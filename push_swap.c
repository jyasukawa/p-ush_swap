#include "push_swap.h"

static void	ft_select_sort(t_list **a, t_list **b, size_t size)
{
	if (size == 2)
		ft_sort_2(a);
	if (size == 3)
		ft_sort_3(a);
	if (size == 4 || size == 5)
		ft_sort_4or5(a, b, size);
	if (5 < size)
		ft_sort_over5(a, b, size);
}

int	main(int argc, char **argv)
{
	static t_list	*a;
	static t_list	*b;
	static size_t	size;
	int						nbr;

	if (argc == 1)
		exit(0);
	if (argc == 2)
		size = ft_for_zsh(&a, argv[1]);
	if (argc > 2)
	{
		while (argc != 1)
		{
			argc--;
			nbr = ft_atoi_new(argv[argc]);
			ft_init_stack_a(&a, nbr);
			size++;
		}
	}
	ft_check_dup(&a, size);
	ft_store_index(&a, size);
	ft_is_sorted(&a);
	ft_select_sort(&a, &b, size);
	ft_free_stack(&a);
	exit(0);
}
