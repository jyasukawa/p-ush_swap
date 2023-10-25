#include "push_swap.h"

size_t	ft_min_index(t_list **a)
{
	t_list	*tmp;
	size_t	i;

	tmp = *a;
	i = tmp->index;
	while (tmp != NULL)
	{
		if (i > tmp->index)
			i = tmp->index;
		tmp = tmp->next;
	}
	return (i);
}

size_t	ft_max_index(t_list **a_b)
{
	t_list	*tmp;
	size_t	i;

	tmp = *a_b;
	i = tmp->index;
	while (tmp != NULL)
	{
		if (i < tmp->index)
			i = tmp->index;
		tmp = tmp->next;
	}
	return (i);
}

size_t	ft_stack_len(t_list **a_b)
{
	t_list	*tmp;
	size_t	len;

	tmp = *a_b;
	len = 1;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

static size_t	*ft_copy_index(t_list *a_b, size_t *idx_array)
{
	size_t	i;

	i = 0;
	while (a_b != NULL)
	{
		idx_array[i] = a_b->index;
		a_b = a_b->next;
		i++;
	}
	return (idx_array);
}

int	ft_is_closer(t_list **a_b, size_t index, size_t len, t_list **another)
{
	t_list	*tmp;
	size_t	*idx_array;
	size_t	i;

	idx_array = (size_t	*)malloc(sizeof(size_t) * len);
	if (idx_array == NULL)
	{
		ft_free_stack(a_b);
		ft_free_stack(another);
		ft_exit_error();
	}
	tmp = *a_b;
	idx_array = ft_copy_index(tmp, idx_array);
	i = 0;
	while (idx_array[i] != index)
		i++;
	len = len - i;
	free(idx_array);
	if (i < len)
		return (0);
	return (1);
}
