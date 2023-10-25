#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_list
{
	int						number;
	size_t				index;
	struct s_list	*next;
}				t_list;

void		sa(t_list **a);
void		pa(t_list **a, t_list **b);
void		pb(t_list **a, t_list **b);
void		ra(t_list **a);
void		rb(t_list **b);
void		rra(t_list **a);
void		rrb(t_list **b);

size_t	ft_for_zsh(t_list **a, char *str);
void 		ft_free_strs(char **strs);
char		**ft_split_space(char *s);

void		ft_exit_error(void);
void		ft_free_stack(t_list **a_b);
int 		ft_atoi_new(char *str);

void		ft_init_stack_a(t_list **a, int nbr);
int			*ft_copy_number(t_list *a, int *n_array);
int 		*ft_make_n_array(t_list **a, size_t size);
void		ft_check_dup(t_list **a, size_t size);

void		ft_is_sorted(t_list **a);
void		ft_store_index(t_list **a, size_t size);

size_t	ft_min_index(t_list **a);
size_t	ft_max_index(t_list **a_b);
size_t	ft_stack_len(t_list **a_b);
int			ft_is_closer(t_list **a_b, size_t index, size_t len, t_list **another);

void		ft_sort_2(t_list **a);
void		ft_sort_3(t_list **a);
void		ft_sort_4or5(t_list **a, t_list **b, size_t size);
void		ft_sort_over5(t_list **a, t_list **b, size_t size);
void		ft_complete_stack_a(t_list **a, t_list **b);

#endif