#include "push_swap.h"

void	ft_init_stack_a(t_list **a, int nbr)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
	{
		ft_free_stack(a);
		ft_exit_error();
	}
	new->number = nbr;
	new->next = *a;
	*a = new;
}

int	*ft_copy_number(t_list *a, int *n_array)
{
	size_t	i;

	i = 0;
	while (a != NULL)
	{
		n_array[i] = a->number;
		a = a->next;
		i++;
	}
	return (n_array);
}

int *ft_make_n_array(t_list **a, size_t size)
{
	t_list	*tmp;
	int			*n_array;

	n_array = (int *)malloc(sizeof(int) * size);
	if (n_array == NULL)
	{
		ft_free_stack(a);
		ft_exit_error();
	}
	tmp = *a;
	n_array = ft_copy_number(tmp, n_array);
	return (n_array);
}

void	ft_check_dup(t_list **a, size_t size)
{
	int			*n_array;
	size_t	i;
	size_t	j;
	int			nbr;

	n_array = ft_make_n_array(a, size);
	i = 0;
	while (i < size)
	{
		nbr = n_array[i];
		j = i + 1;
		while (j < size)
		{
			if (n_array[j] == nbr)
			{
				free(n_array);
				ft_free_stack(a);
				ft_exit_error();
			}
			j++;
		}
		i++;
	}
	free(n_array);
}
