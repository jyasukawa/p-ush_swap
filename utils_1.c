#include "push_swap.h"

void	ft_exit_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	ft_free_stack(t_list **a_b)
{
	t_list	*tmp;

	if (*a_b == NULL)
		ft_exit_error();
	while (*a_b != NULL)
	{
		tmp = (*a_b)->next;
		free(*a_b);
		*a_b = tmp;
	}
}

static void ft_skip(char **str, int *sign, size_t *i)
{
	if ((*str)[*i] == '\0')
		ft_exit_error();
	if ((*str)[*i] == '-' || (*str)[*i] == '+')
	{
			if ((*str)[*i] == '-')
					*sign = -1;
			(*i)++;
			if ((*str)[*i] == '\0')
				ft_exit_error();
	}
}

static void ft_check_overflow(long long nbr, unsigned int digit, int sign)
{
	if (sign < 0)
	{
		if (INT_MIN > (-1) * nbr * 10 - digit)
			ft_exit_error();
	}
	 if (sign > 0)
	{
		if (INT_MAX < nbr * 10 + digit)
			ft_exit_error();
	}
}

int ft_atoi_new(char *str)
{
	size_t		i;
	long long	nbr;
	int				sign;

	i = 0;
	sign = 1;
	ft_skip(&str, &sign, &i);
	nbr = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			ft_check_overflow(nbr, (str[i] - '0'), sign);
			nbr = (10 * nbr) + (str[i] - '0');
			i++;
		}
		else
			ft_exit_error();
	}
	return ((int)(sign * nbr));
}
