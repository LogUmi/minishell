/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:47:51 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/15 10:47:59 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	send_cmdes(int j, int palier, t_tab *t, int *nd)
{
	int		k;
	int		svar;
	char	*svsplit;

	k = 0;
	j += (*t->flag);
	svar = nd[j];
	svsplit = t->nsplit[j];
	while (k < (j - palier))
	{
		t->nsplit[j - k] = t->nsplit[j - k - 1];
		nd[j - k] = nd[j - k - 1];
		k++;
	}
	t->nsplit[palier] = svsplit;
	nd[palier] = svar;
	(*t->flag)++;
}

char	**ft_freetabs_ocmd(char **tab, int *tv)
{
	int	i;

	i = 0;
	if (**tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
	if (tv)
		free(tv);
	return (NULL);
}

static char	**ft_tabdup(char **tab)
{
	char	**new;
	int		i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	new = (char **)malloc(sizeof(char *) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (tab[i] != NULL)
	{
		new[i] = ft_strdup(tab[i]);
		if (!new[i])
			return (ft_freetabs_ocmd(new, NULL));
		i++;
	}
	new[i] = 0;
	return (new);
}

void	order_cmdes_0(t_tab *t, char **s, int *nd, int i)
{
	int		j;
	int		*ty;
	int		palier;

	ty = t->var;
	while (s[i] != NULL)
	{
		(*t->flag) = 0;
		palier = i;
		while (s[i] != NULL && (ty[i] != PIP && !(ty[i] > RDIR_OUT)))
			i++;
		j = i - 1;
		while (j >= palier)
		{
			if (ty[j] == 0 && (j == palier || (j != 0 && ty[j - 1] == 0)))
				send_cmdes(j, palier, t, nd);
			j--;
		}
		if (s[i] != NULL)
			i++;
	}
}

int	order_cmdes(t_tab *t)
{
	char	**ns;
	int		*nd;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	t->flag = &flag;
	while (t->split[i] != NULL)
		i++;
	ns = ft_tabdup(t->split);
	if (!ns)
		return (-1);
	nd = dup_tab_int(t->var, i, ns);
	if (!nd)
		return (-1);
	t->nsplit = ns;
	order_cmdes_0(t, t->split, nd, 0);
	ft_freetabs_ocmd(t->split, t->var);
	t->split = ns;
	t->var = nd;
	t->nsplit = NULL;
	t->flag = NULL;
	return (0);
}
