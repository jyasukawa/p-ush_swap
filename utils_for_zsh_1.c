#include "push_swap.h"

static void	ft_init_stack_a_for_zsh(t_list **a, int nbr, char **strs)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
	{
		ft_free_strs(strs);
		ft_free_stack(a);
		ft_exit_error();
	}
	new->number = nbr;
	new->next = *a;
	*a = new;
}

size_t	ft_for_zsh(t_list **a, char *str)
{
	size_t	size;
	size_t	i;
	char		**strs;
	int			nbr;

	strs = ft_split_space(str);
	if (strs[0] == NULL)
	{
		free(strs);
		ft_exit_error();
	}
	i = 0;
	while (strs[i] != NULL)
		i++;
	size = i;
	while (i > 0)
	{
		i--;
		nbr = ft_atoi_new(strs[i]);
		ft_init_stack_a_for_zsh(a, nbr, strs);
	}
	ft_free_strs(strs);
	return (size);
}
