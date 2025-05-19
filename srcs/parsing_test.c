#include "minishell.h"

void	print_split(t_tab *t)
{
	int	i;

	i = 0;
	if (t->split)
	{
		ft_printf("Tableau issu du split :\n");
		if (t->var)
		{
			while (t->split[i])
			{
				ft_printf("chaine : %s \t type : %d\n", t->split[i], t->var[i]);
				i++;
			}
		}
		else
		{
			while (t->split[i])
				ft_printf("chaine : %s\n", t->split[i++]);
		}
	}
	else
		ft_printf("Pas de tableau issu du split\n");
}

void	print_tree_right(t_bin *tr, int j)
{
	int	i;

	i = 0;
	while (i++ < j + 1)
		ft_printf("         ");
	if (tr->right != 0)
		print_tree_right(tr->right, j + 1);
	ft_printf("leave: %p dad: %p left: %p ", tr, tr->dad, tr->left);
	ft_printf("right: %p\n", tr->right);
	i = 0;
	while (i++ < j + 1)
		ft_printf("         ");
	i = 0;
	ft_printf("type: %d ... ", tr->type);
	ft_printf("Valeurs:");
	while (tr->val[i])
		ft_printf(" %s §", tr->val[i++]);
	ft_printf("\n");
}

void	print_tree(t_tab *t)
{
	t_bin	*tr;
	size_t	i;

	tr = *t->tree;
	ft_printf("\nData Tree\n");
	while (tr)
	{
		ft_printf("leave: %p dad: %p left: %p ", tr, tr->dad, tr->left);
		ft_printf("right: %p\n", tr->right);
		i = 0;
		ft_printf("type: %d ... ", tr->type);
		ft_printf("Valeurs:");
		while (tr->val[i])
			ft_printf(" %s §", tr->val[i++]);
		ft_printf("\n");
		if (tr->right)
			print_tree_right(tr->right, 0);
		tr = tr->dad;
		if (tr)
			ft_printf ("Go to dad\n");
		else
			ft_printf ("End\n");
	}
}

void	print_heredoc(t_tab *t, char *s, int i, int j)
{
	int	fd;

	if (t->hrdfiles)
	{
		while (t->hrdfiles[i] != NULL)
		{
			j = 0;
			ft_printf ("\nfichier heredoc : %s\n", t->hrdfiles[i]);
			fd = open(t->hrdfiles[i], O_RDONLY);
			if (fd == -1)
				ft_printf("ouverture fichier impossible\n");
			else
			{
				while (j == 0)
				{
					s = get_next_lines(fd);
					if (!s)
						j = 1;
					else
						ft_printf("%s", s);
				}
				close(fd);
				ft_printf("\n");
			}
			i++;
		}
	}
}
