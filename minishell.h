/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:51:14 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/16 17:52:11 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <string.h>
# include <errno.h>
# include <signal.h>
# include <termios.h>
# include <limits.h>
# include "readline/readline.h"
# include "readline/history.h"
# include "libft/includes/libft.h"

# define ERR -1
# define CMD 0
# define BUI 1
# define PIP 2
# define RDIR_IN 3
# define RDIR_OUT 4
# define AND 5
# define OR  6
# define SEP 7
# define ACC 8
# define FD 9

typedef struct s_lst
{
	char			*content;
	struct s_lst	*next;
}					t_lst;

extern int		g_sign;

typedef struct s_bin
{
	int				type;
	char			**val;
	struct s_bin	*dad;
	struct s_bin	*left;
	struct s_bin	*right;
}					t_bin;

typedef struct s_tab
{
	char			**split;
	char			**nsplit;
	char			*input;
	char			*prompt;
	char			*temp;
	char			file_h[256];
	t_bin			**tree;
	t_lst			*env_list;
	t_lst			*exp_env;
	char			**env;
	int				pid;
	int				*var;
	int				*flag;
	int				fd_history;
	int				nlhd;
	t_bin			*hrdoc[256];
	char			**hrdfiles;
	char			**history;
	int				fd_hrd;
	int				stdin_sav;
	int				stdout_sav;
	int				stderr_sav;
	int				npip;
	int				fpip;
	int				pip[256][2];
	int				npid;
	int				pide[256];
	t_bin			*rf_in;
	t_bin			*rf_out;
	t_bin			*rf_oout;
	int				pipe_in;
	int				pipe_out;
	int				ex_status;
	unsigned char	c;
	unsigned char	c1;
	unsigned char	q1;
	unsigned char	q2;
	int				n_wrds;
	size_t			ii;
}					t_tab;

void	set_shlvl(t_tab *t);
int		check_dash(char *arg);
char	*remove_plus_sign(char	*str);
void	add_var_in_list(t_tab *t, t_lst *var, t_lst *tmp_exp, t_lst *tmp_env);
t_lst	*in_env(t_lst *list, t_lst *var);
char	*add_prompt_color(char *prompt);
void	init_export_env(t_tab *t, char **env);
void	print_export_list(t_lst *list);
void	add_export_format(t_lst *exp_lst);
t_lst	*ft_lst_back(t_lst **lst, t_lst *new);
t_lst	*ft_listnew(char *content);
void	exec_builtin(t_tab *t, char **val);
int		exec_export(t_tab *t, char **val);
int		builtin_echo(char **args, t_tab *t);
int		builtin_exit(t_tab *t, char **val);
int		builtin_pwd(void);
int		builtin_cd(t_tab *t, char **val);
int		check_export_input(char *args);
void	init_export_list(t_tab *t);
char	*ft_prompt(t_lst *env_list);
void	main_loop(t_tab *t);
void	ft_setenv(t_tab *t, t_lst *var);
void	init_env(t_lst **env_list, char **env);
int		ft_unsetenv(t_lst **env_list, char **var, t_tab *t, int i);
char	*ft_getenv(t_lst *env_list, char *str);
char	*ft_trim_start(char *str, char *set);
void	print_list(t_lst *list);
char	*ft_trim_start(char *str, char *set);
char	*set_path(char **t_path, char *argv, char *path);
char	*get_path(t_tab *t, char *argv);
char	**get_opt(char *argv);
char	*get_cmd(char *argv);
void	cmd_nf(char *argv);
void	file_error(char *file);
void	free_t_tab(char **tab);
void	free_list(t_lst **list);
void	free_node(t_lst *list);

char	**blade_alloc(t_tab *t, size_t len, size_t ii, size_t j);
char	**blade_loop_1(t_tab *t, int *flag, size_t *i, size_t j);
int		check_error_cmde(char *s, int way, int err);
int		check_error_cmde_0(char *s, int way);
int		check_in_redir(char *s, size_t i, size_t j, size_t len);
void	check_next_redir(char *s, size_t i, size_t j, size_t len);
void	check_pipe(t_tab *t);
void	ctrl_d_hrd(t_tab *t, t_bin *tr);
int		delchar(char *s, size_t *i, int *f, size_t flag);
void	do_redir_out(t_bin *tr);
int		*dup_tab_int(int *d, int len, char **ns);
int		error_cluster(t_tab *t);
void	error_execve(t_bin *tr, t_tab *t);
int		error_rfile_check(t_tab *t, int err, t_bin *palier, int flag);
void	exec_builtin_pipe(t_tab *t, char **val);
void	exec_cmd(t_bin *tr, t_tab *t, int err);
int		exec_com(t_tab *t);
int		exec_pipe(t_tab *t);
int		exec_rdir(t_tab *t);
int		exit_check(t_tab *t, char *msg, int ret);
int		expand(t_tab *t, size_t i, size_t j, int f);
int		expban(char c);
int		expdoll(char c);
int		expvare(char c);
int		filename_size(t_bin *tr);
int		free_expand(t_tab *t, int ret);
void	free_heredoc(t_tab *t);
void	free_tree(t_bin **root, t_tab *t);
void	ft_close_history(t_tab *t);
char	**ft_freetabs_ocmd(char **tab, int *tv);
void	ft_init_history(t_tab *t, char *s, int i, int j);
void	ft_write_history(t_tab *t);
int		get_cmde(t_tab *t);
int		get_heredocs(t_tab *t, t_bin *palier, t_bin *tr, size_t i);
int		get_heredocs_1(t_tab *t, t_bin *tr[], size_t i, int expd);
char	*get_var_env(char *s, t_tab *t);
int		hrd_child(t_tab *t, t_bin *tr[], int status, int i);
int		hrd_expand(char *s, size_t *i, t_tab *t, size_t k);
void	hrd_get_rid_file(char *file);
void	hrd_ignore_bs(char **s, t_tab *t);
int		hrd_is_quote(char *s);
int		hrd_send_to_file_0(char *s, char *file, t_tab *t);
int		hrd_send_to_file_1(char *s, char *file, t_tab *t, size_t i);
void	hrd_set_flag(char c, t_tab *t, int *f);
void	hrd_sup_char(char *s, size_t i);
void	hrd_sup_quotes(char **s, t_tab *t);
char	**init_tab_env(t_tab *t, t_lst *lst, int i, char **tab);
int		is_heredoc(t_tab *t, int j);
t_bin	*last_leaf(t_bin **tr);
void	loop_1_1(char *s, int *flag, size_t *i, size_t *n);
void	loop_1_2(char *s, int *flag, size_t *i, size_t *n);
int		loop_in_loop_2(char *s, size_t i, int f);
char	**magic_split(t_tab *t);
char	**magic_split_free(char **tab, int j);
int		make_tree(t_tab *t, size_t j, size_t k);
int		newloop_free(t_tab *t);
int		order_cmdes(t_tab *t);
void	print_err_file(t_tab *t);
int		prt_errf(char *s, char *msg, int flag, t_tab *t);
void	redir_init(t_tab *t);
int		run_cmde(t_bin *tr, t_tab *t);
char	**scd_blade(t_tab *t);
int		set_pipe(t_bin *tr, t_tab *t, t_bin *palier);
int		set_rdir(t_bin *tr, t_tab *t);
int		set_err_rdir(t_bin *tr);
void	set_signals(void);
void	silent_signals(void);
void	stdin_to_terminal(void);
void	stdout_to_terminal(void);
int		synt_error_test(t_tab *t);
int		synt_error_test_4(t_bin *tr, char *s, size_t len);
void	tree_add_dad(t_bin **root, t_bin *new);
void	tree_add_right(t_bin **root, t_bin *new);
void	tree_check_arg(t_tab *t, size_t j, size_t *k);
void	tree_free_left(t_bin *leave);
void	tree_free_right(t_bin *leave);
t_bin	*tree_newleave(t_tab *t, char **ntab, int ntype);
void	tree_pruning(t_tab *t);
void	tree_reducing(t_tab *t);
void	unset_signals(void);
int		unclosed_quotes(char *str);
void	wait_children(t_tab *t);

void	print_split(t_tab *t);
void	print_tree(t_tab *t);
void	print_heredoc(t_tab *t, char *s, int i, int j);
#endif
