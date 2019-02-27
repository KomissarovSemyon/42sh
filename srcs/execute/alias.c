int		set_alias_arg(t_list **args)
{
	int		i;
	char	*arg1;
	char	**alias;

	arg1 = (char *)(*args)->data;
	if (!(alias = get_alias(arg1)))
		return (0);
	free(ft_pop(args));
	i = 0;
	while (alias[i])
		i++;
	while (--i >= 0)
		ft_push(args, alias[i]);
	free(alias);
	return (0);
}