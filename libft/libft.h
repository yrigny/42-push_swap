/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: yifanr <yifanr@student.42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/10 17:32:53 by yrigny	       #+#    #+#	      */
/*   Updated: 2023/11/19 15:59:31 by yrigny           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <ctype.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <fcntl.h>

/* basic */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ft_ptintf */
typedef struct s_flags
{
	bool	left;
	bool	plus;
	bool	space;
	bool	hash;
	bool	zero;
	int		width;
	bool	dot;
	int		precis;
	char	type;
}		t_flags;

int		ft_printf(const char *fstr, ...);
int		putnchar(int n, char c);
int		getulen(unsigned long num, unsigned int baselen);
long	unsign(long n);
void	printer(const char *fstr, va_list *p_args, int *p_n);
void	fprinter(const char *fstr, va_list *p_args, int *p_n);
void	iniflagset(t_flags *p_flagset);
void	parseflag(t_flags *p_flagset, const char *fstr);
void	putunbr_base(unsigned long nbr, char *base, unsigned int baselen);
void	fprinter_c(t_flags flagset, va_list *p_args, int *p_n);
void	fprinter_s(t_flags flagset, va_list *p_args, int *p_n);
void	fprinter_p(t_flags flagset, va_list *p_args, int *p_n);
void	fprinter_d(t_flags flagset, va_list *p_args, int *p_n);
void	fprinter_u(t_flags flagset, va_list *p_args, int *p_n);
void	fprinter_x(t_flags flags, va_list *p_args, int *p_n, char *base);

/* get_next_line */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_lst
{
	char			*content;
	struct s_lst	*next;
}			t_lst;

char	*get_next_line(int fd);
int		read_n_stash(int fd, ssize_t *p_bytes_read, t_lst **p_stash);
int		count_line_len(t_lst *stash);
int		find_endl(t_lst *stash);
int		copy_line(t_lst *stash, char **p_line);
void	clean_stash(t_lst **p_stash, int line_len);
void	ft_lstdel_front(t_lst **p_lst);
void	ft_lstadd(t_lst **lst, t_lst *new);
void	ft_memcp(char *dest, char *src, size_t n);
void	free_stash(t_lst **p_stash);

#endif
