#include "push_swap.h"

static size_t	ft_count_words(char *s)
{
  size_t  i;
	size_t  count;

  i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && ((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
			i++;
		if (s[i])
			count++;
		while (s[i] && (!(s[i] >= 9 && s[i] <= 13) && s[i] != 32))
			i++;
	}
	return (count);
}

static size_t	ft_word_len(char *s)
{
  size_t  i;

  i = 0;
	while (s[i] && (!(s[i] >= 9 && s[i] <= 13) && s[i] != 32))
    i++;
	return (i);
}

static char	*ft_malloc_str(char *s, size_t len)
{
	size_t	i;
	char		*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void ft_free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i] != NULL)
		free(strs[i++]);
	free(strs);
}

char	**ft_split_space(char *s)
{
	size_t	i;
	char		**strs;

	if (s == NULL)
		ft_exit_error();
	strs = (char **)malloc(sizeof(char *) * (ft_count_words(s) + 1));
	if (strs == NULL)
		ft_exit_error();
	i = 0;
	while (*s)
	{
    while (*s && ((*s >= 9 && *s <= 13) || *s == 32))
      s++;
		if (*s != '\0')
  		strs[i++] = ft_malloc_str(s, ft_word_len(s));
    if (i > 0 && strs[i - 1] == NULL)
    {
      ft_free_strs(strs);
      ft_exit_error();
    }
		if (*s != '\0')
    	s = s + ft_word_len(s);
	}
  strs[i] = NULL;
	return (strs);
}
