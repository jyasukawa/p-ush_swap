#include "push_swap.h"

void	sa(t_list **a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *a;
	tmp2 = tmp1->next->next;
	*a = (*a)->next;
	(*a)->next = tmp1;
	(*a)->next->next = tmp2;
	write(1, "sa\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *b;
	*b = tmp->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	*a = tmp->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
}
