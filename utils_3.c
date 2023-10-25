#include "push_swap.h"

void	ft_is_sorted(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next != NULL)
	{
		if ((tmp->index + 1) == tmp->next->index)
			tmp = tmp->next;
		else
			return ;
	}
	ft_free_stack(a);
	exit(0);
}

static int	ft_find_index(int *i_array, int nbr)
{
	size_t	i;

	i = 0;
	while (i_array[i] != nbr)
		i++;
	return (i);
}

static int	*ft_bubble_sort(int *i_array, size_t size)
{
	size_t	i;
	size_t	j;
	int			tmp;

	i = 0;
	tmp = 0;
	while (i < size - 1)
	{
		j = size - 1;
		while (j > i)
		{
			if (i_array[j - 1] > i_array[j])
			{
				tmp = i_array[j - 1];
				i_array[j - 1] = i_array[j];
				i_array[j] = tmp;
			}
			j--;
		}
		i++;
	}
	return (i_array);
}

static int	*ft_copy_array(int *i_array, int *n_array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		i_array[i] = n_array[i];
		i++;
	}
	return (i_array);
}

void	ft_store_index(t_list **a, size_t size)
{
	t_list	*tmp;
	size_t	i;
	int			*n_array;
	int			*i_array;

	n_array = ft_make_n_array(a, size);
	i_array = (int *)malloc(sizeof(int) * size);
	if (i_array == NULL)
	{
		free(n_array);
		ft_free_stack(a);
		ft_exit_error();
	}
	i_array = ft_copy_array(i_array, n_array, size);
	i_array = ft_bubble_sort(i_array, size);
	i = 0;
	tmp = *a;
	while (tmp != NULL)
	{
		tmp->index = ft_find_index(i_array, n_array[i]);
		tmp = tmp->next;
		i++;
	}
	free(n_array);
	free(i_array);
}
