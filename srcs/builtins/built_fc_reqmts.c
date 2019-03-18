#include "builtins.h"
#include "readline.h"
#include "vector.h"
#include "libft.h"

void	built_fc_swap_limits(size_t *left_limit, size_t *right_limit)
{
	size_t	tmp;

	tmp = *right_limit;
	*right_limit = *left_limit;
	*left_limit = tmp;
}

void	built_fc_set_limits_default(size_t *left_limit, size_t *right_limit, void *fc_history)
{
	*right_limit = vector_get_len(fc_history);
	if (*right_limit)
		(*right_limit)--;
	if (*right_limit < 15)
		*left_limit = 0;
	else
		*left_limit = *right_limit - 14;
}

int		built_fc_usage(int error)
{
	if (error == FC_ERROR_FLAGS)
	{
		array_add("fc usage: \n", ft_strlen("fc usage: \n"));
		array_add("  fc [-r] [-e editor] [first [last]]\n",
				ft_strlen("  fc [-r] [-e editor] [first [last]]\n"));
		array_add("  fc -l [-nr] [first [last]]\n",
				ft_strlen("  fc -l [-nr] [first [last]]\n"));
		array_add("  fc -s [old=new] [first]\n",
				ft_strlen("  fc -s [old=new] [first]\n"));
	}
	if (error == FC_ERROR_ARGS)
		array_add("fc: too many arguments\n", ft_strlen("fc: too many arguments\n"));
	if (error == FC_ERROR_EVENT)
		array_add("fc: no such event\n", ft_strlen("fc: no such event\n"));
	array_flush();
	return (0);
}