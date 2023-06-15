#include "shell.h"

bool	expander_check(char *input)
{
	int		i;
	bool	expand;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\"' && input[i + 1] == '\'')
			expand = true;
		if (input[i] == '\'' && input[i + 1] == '\"')
			expand = false;
		if (input[i] == '\'')
			expand = false;
		else
			expand = true;
		i++;
	}
	return (expand);
}

char	*get_dollar_env(char *input)
{
	t_env	*env;

	env = get_env(g_shell.env, input);
	if (!env)
	{
		g_shell.expanded.exit = true;
		return (ft_strdup(""));
	}
	return (env->val);
}
