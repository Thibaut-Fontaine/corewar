/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:38:48 by mperronc          #+#    #+#             */
/*   Updated: 2017/05/02 17:07:27 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef int	t_bool;
# define TRUE 1
# define FALSE 0

typedef struct		s_specs
{
	char			*data;
	wchar_t			*wdata;
	t_bool			minus;
	t_bool			plus;
	t_bool			space;
	t_bool			sharp;
	t_bool			zero;
	t_bool			pointer;
	unsigned int	width;
	unsigned int	precision;
	char			length;
	char			type;
	t_bool			percent;
	t_bool			valid;
	t_bool			nullchar;
}					t_specs;

int					ft_printf(const char *restrict format, ...);
void				init_specs(t_specs *specs);
const char			*parse_specs(const char *restrict string, t_specs *specs);
const char			*parse_flags(const char *restrict string, t_specs *specs);
const char			*parse_length(const char *restrict string, t_specs *specs);
const char			*parse_precision(const char *restrict string,
					t_specs *specs);
const char			*parse_type(const char *restrict string, t_specs *specs);
const char			*parse_width(const char *restrict string, t_specs *specs);
char				*ft_strpad(char *str, size_t width, char side);
char				*ft_spacetozero(char *str);
void				handle_prefix_x(t_specs *specs);
void				handle_prefix(t_specs *specs, char c);
char				*handle_num_precision(char *str, size_t precision);
size_t				format_stuff(va_list *args, t_specs *specs);
void				format_char(va_list *args, t_specs *specs);
void				format_hex(va_list *args, t_specs *specs);
void				format_str(va_list *args, t_specs *specs);
void				format_oct(va_list *args, t_specs *specs);
void				format_udec(va_list *args, t_specs *specs);
void				format_dec(va_list *args, t_specs *specs);
char				*ft_itoa_base16(intmax_t n, int base);
char				*ft_uitoa_base16(uintmax_t n, int base);
char				*ft_strtoupper(char *str);
int					ft_strcnt(char *str, char c);
char				*ft_strcut(char *str, int n);
char				*ft_strtrns(char *str, int n);
size_t				ft_nbrlen(intmax_t n);
size_t				ft_unbrlen(uintmax_t n);
char				*strip_sign(char *str);
intmax_t			ft_ltoi(const char *str);
int					ft_putwchar(wchar_t wc);
int					ft_putwstr(wchar_t *wstr);
void				format_wchar(va_list *args, t_specs *specs);
void				format_wstr(va_list *args, t_specs *specs);
wchar_t				*ft_wstrchr(const wchar_t *s, wchar_t c);
wchar_t				*ft_wstrcut(wchar_t *str, int n);
wchar_t				*ft_wstrdup(const wchar_t *str);
size_t				ft_wstrlen(const wchar_t *s);
wchar_t				*ft_wstrncpy(wchar_t *dst, const wchar_t *src, size_t n);
wchar_t				*ft_wstrnew(size_t size);
wchar_t				*ft_wstrpad(wchar_t *str, size_t width, char side);

#endif
