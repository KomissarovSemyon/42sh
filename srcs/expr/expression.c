#include "expression.h"

unsigned int		g_excurtok;
void				*g_extokens = NULL;
int					g_exprerr;

long int	expression(char *arg)
{
	t_lexer		*lexer;
	t_astree	*root;

	lexer = exprlexer(arg, ft_strlen(arg));
	g_extokens = lexer->lexems;
	g_excurtok = 0;
	g_exprerr = 0;
	root = expr();
	print_astree(root);
	/* return (exprexecute(ast)); */
	return (0);
}
