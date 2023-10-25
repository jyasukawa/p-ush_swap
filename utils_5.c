#include "push_swap.h"

void	ft_sort_2(t_list **a)
{
	if ((*a)->next->index < (*a)->index)
		sa(a);
}

void	ft_sort_3(t_list **a)
{
	if ((*a)->index == ft_max_index(a))
		ra(a);
	if ((*a)->index == ft_min_index(a) && (*a)->next->index == ft_max_index(a))
	{
		rra(a);
		sa(a);
	}
	if ((*a)->index != ft_min_index(a) && (*a)->index > (*a)->next->index)
		sa(a);
	if ((*a)->index != ft_min_index(a) && (*a)->index < (*a)->next->index)
		rra(a);
}

void	ft_sort_4or5(t_list **a, t_list **b, size_t size)
{
	int	i;
	int	to_b;

	if (size == 4)
		to_b = 1;
	else
		to_b = 2;
	i = 0;
	while (i < to_b)
	{
		if ((*a)->index > ft_min_index(a) && !ft_is_closer(a, ft_min_index(a), ft_stack_len(a), b))
			ra(a);
		else if ((*a)->index > ft_min_index(a) && ft_is_closer(a, ft_min_index(a), ft_stack_len(a), b))
			rra(a);
		else
		{
			pb(a, b);
			i++;
		}
	}
	ft_sort_3(a);
	while (*b != NULL)
		pa(a, b);
}

void	ft_sort_over5(t_list **a, t_list **b, size_t size)
{
	size_t	i;
	size_t	range;

	if (size <= 100)
		range = 15;
	else
		range = 30;
	i = 0;
	while (*a != NULL)
	{
		if (i > 1 && (*a)->index <= i)
		{
			pb(a, b);
			i++;
			rb(b);
		}
		else if ((*a)->index <= i + range)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->index >= i)
			ra(a);
	}
	ft_complete_stack_a(a, b);
}

void	ft_complete_stack_a(t_list **a, t_list **b)
{
	while (*b != NULL)
	{
		if ((*b)->index != ft_max_index(b) && !ft_is_closer(b, ft_max_index(b), ft_stack_len(b), a))
			rb(b);
		else if ((*b)->index != ft_max_index(b) && ft_is_closer(b, ft_max_index(b), ft_stack_len(b), a))
			rrb(b);
		else if ((*b)->index == ft_max_index(b))
			pa(a, b);
	}
}
