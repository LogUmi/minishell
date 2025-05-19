/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:17:27 by lgerard           #+#    #+#             */
/*   Updated: 2025/03/26 20:30:01 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdarg.h>

# ifndef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 20000
# endif
# if GNL_BUFFER_SIZE < 0
#  undef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 0
# endif
# if GNL_BUFFER_SIZE > 1000000
#  undef GNL_BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif
# ifndef GNL_STATIC_SIZE
#  define GNL_STATIC_SIZE 21000
# endif
# if GNL_STATIC_SIZE < 0
#  undef GNL_STATIC_SIZE
#  define GNL_STATIC_SIZE 0
# endif
# if GNL_STATIC_SIZE > 21000
#  undef GNL_STATIC_SIZE
#  define GNL_STATIC_SIZE 21000
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
int		ft_len(long long i, int nb, int u);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_printf(const char *str, ...);
int		ft_printstr(const char *str, int *nsp);
int		ft_putint(int i, int *ndig);
int		ft_printunsbase(unsigned int i, char *bs, int *ndig);
int		ft_printpointer(void *p, char *bs, int *ndig);
int		ft_putcf(int i, int n);
int		ft_putccf(int i, int n, int *nsp);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_putnsbase(unsigned int i, char *bs, int *ndig);
int		ft_putnbrullbase(unsigned long long i, char *bs);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_putstrf(const char *str, int *nsp);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strlenf(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strncpygnl(char *src, char *dst, int n, int way);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*get_next_linedm(int fd);
char	*get_next_lined(int fd);
char	*get_next_linesm(int fd);
char	*get_next_lines(int fd);
#endif
