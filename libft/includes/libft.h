/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 20:35:19 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/23 15:00:22 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define OUTPUT_LEN 4096

typedef int			t_bool;
# define FALSE 0
# define TRUE 1

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_endl
{
	int				fd;
	char			*s;
}					t_endl;

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isalnum(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);

void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);

char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_putlstmem(t_list *lst, t_bool carriage_return);
size_t				ft_lstlen(t_list *lst);
void				ft_lstaddend(t_list *lst, t_list *new);
void				ft_lstjoin(t_list *lst1, t_list *lst2);
t_list				*ft_lstinsert(t_list **dst, t_list *lst, size_t position);
char				*ft_strfjoin(char **s1, char const *s2);
void				ft_putwstr_fd(wchar_t const *s, int fd);
void				ft_putwchar_fd(wchar_t c, int fd);
const char			*ft_bytobi(unsigned char c);
const char			*ft_bytohex(unsigned char c, t_bool big_or_little);
void				ft_putbin_fd(const unsigned char *s,
		size_t len, size_t mpl, int fd);
void				ft_puthex_fd(const unsigned char *s,
		size_t len, size_t mpl, int fd);
void				ft_memrev(unsigned char *str, size_t len);
char				ft_bitoby(unsigned int n);
uintmax_t			ft_endian(uintmax_t i, t_bool is_signed);
void				ft_putadr_fd(void *p, int fd);
void				ft_putlnbr_fd(intmax_t n, int fd);
int					ft_swrite(int fd, const void *buf, size_t count);
char				*ft_sget(int fd);
void				ft_sprint(int fd);
void				*ft_memdup(const void *s, size_t len);
size_t				ft_strwlen(const wchar_t *s);
char				*ft_strnchr(const char *s, int c, size_t n);
void				ft_swap(uintmax_t *a, uintmax_t *b);

ssize_t				ft_putchar_fdr(char c, int fd);
ssize_t				ft_putstr_fdr(char const *s, int fd);
ssize_t				ft_putadr_fdr(void *p, int fd);
ssize_t				ft_putwstr_fdr(wchar_t const *s, int fd);
ssize_t				ft_putwchar_fdr(wchar_t c, int fd);
ssize_t				ft_putnbr_fdr(int n, int fd);

ssize_t				ft_putnwstr_fdr(wchar_t const *s, size_t n, int fd);
ssize_t				ft_putnstr_fdr(char const *s, size_t n, int fd);

int					ft_dprintf(int fd, const char *format, ...);
int					ft_printf(const char *format, ...);

/*
** ft_put*[bin,hex] display len bytes in binary, with mpl max bytes per line.
*/

#endif
