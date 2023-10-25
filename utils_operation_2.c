#include "push_swap.h"

void	ra(t_list **a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *a;
	tmp2 = *a;
	*a = (*a)->next;
	while (tmp1->next)
		tmp1 = tmp1->next;
	tmp1->next = tmp2;
	tmp1->next->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *b;
	tmp2 = *b;
	*b = (*b)->next;
	while (tmp1->next)
		tmp1 = tmp1->next;
	tmp1->next = tmp2;
	tmp1->next->next = NULL;
	write(1, "rb\n", 3);
}

void	rra(t_list **a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *a;
	tmp2 = tmp1;
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	*a = tmp1->next;
	tmp1->next = NULL;
	(*a)->next = tmp2;
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *b;
	tmp2 = tmp1;
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	*b = tmp1->next;
	tmp1->next = NULL;
	(*b)->next = tmp2;
	write(1, "rrb\n", 4);
}