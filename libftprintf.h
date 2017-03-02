/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:40:27 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/01/13 14:40:30 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <wchar.h>
# include <limits.h>

# define FLAG(c) (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
# define NUM(c) (c >= '0' && c <= '9')
# define ABS(c) (c < 0 ? -c : c)
# define S_T_S ft_strlen(tmp->flags) + 2 + S_T_S2
# define S_T_S2 ft_strlen(ft_itoa(tmp->s_min)) + ft_strlen(ft_itoa(tmp->preci))
# define MOD ft_print_modulo(*elem)
# define CONV "sSpdDioOuUxXcC%\0"
# define PRECI elem.preci
# define ZERO elem.zero
# define PLUS elem.plus
# define SPACE elem.space
# define SMIN elem.s_min
# define SIGN_OR_NOT ((i >= 0 && PLUS) || (i < 0) || (i >= 0 && !PLUS && SPACE))
# define SCD_FLAG(c) (c == 'l' || c == 'h' || c == 'j' || c =='z')
# define INT_MAX_MAX "9223372036854775808"

/*
** define libft de base
*/

# define WHITESPACE(i) (i == ' ' || i == '\t' || i == '\n')

/*
** define get_next_line
*/

# define BUFF_SIZE 1
# define ENDL '\n'

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_arg
{
	int				index;
	char			*flags;
	char			sharp;
	char			zero;
	char			minus;
	char			plus;
	char			space;
	int				type_conv;
	int				s_skip;
	int				s_min;
	int				preci;
	int				scd_flag;
	struct s_arg	*next;
}				t_arg;

int				ft_count_arg(const char *format);
char			*ft_str_flags(int index, const char *str, int mod);
int				ft_printf(const char *format, ...);
int				ft_which_conv(int index, const char *str, int *mod);
void			ft_fill_s_arg(t_arg **first, int n, const char *str);
int				ft_tab_functions(t_arg *elem, va_list *ap);
int				ft_size_min(int index, const char *str, int mod);
wchar_t			*ft_wstrdup(wchar_t *src);
int				ft_wstrlen(wchar_t *str);
int				ft_putwchar(int c);
int				ft_putwstr(wchar_t *s);
int				ft_precision(int index, const char *str, int mod);
int				ft_to_mod_i(int index, int mod, const char *str);
void			ft_s_skip(t_arg *tmp, int index, const char *str, int mod);
int				s_to_print(char *str, t_arg elem);
int				ws_to_print(wchar_t *str, t_arg elem);
char			*ft_strcpy(char *dest, char *src);
int				ft_tmp_next(t_arg *tmp);
void			ft_elem_next(t_arg *elem, int *n);
int				ft_use_arg(t_arg *elem, int *n);
int				get_wchar_size(wchar_t c);
int				ft_print_s(t_arg elem, va_list *ap);
int				ft_print_c(t_arg elem, va_list *ap);

/*
** print_converter sSpdDioOuUxXcC
*/

int				ft_print_s_min(t_arg elem, va_list *ap);
int				ft_print_s_maj(t_arg elem, va_list *ap);
int				ft_print_p(t_arg elem, va_list *ap);
int				ft_print_d(t_arg elem, va_list *ap);
int				ft_print_d_maj(t_arg elem, va_list *ap);
int				ft_print_i(t_arg elem, va_list *ap);
int				ft_print_o(t_arg elem, va_list *ap);
int				ft_print_o_maj(t_arg elem, va_list *ap);
int				ft_print_u(t_arg elem, va_list *ap);
int				ft_print_u_maj(t_arg elem, va_list *ap);
int				ft_print_x(t_arg elem, va_list *ap);
int				ft_print_x_maj(t_arg elem, va_list *ap);
int				ft_print_c_min(t_arg elem, va_list *ap);
int				ft_print_c_maj(t_arg elem, va_list *ap);
int				ft_print_modulo(t_arg elem);
int				ft_print_bad_arg(t_arg elem);

/*
** Tous les ft_itoa
*/

char			*ft_uitoa(uintmax_t n);
char			*ft_itoa(intmax_t n);
char			*ft_itoa_base(intmax_t nb, char *base);
char			*ft_uitoa_base(uintmax_t nb, char *base);
void			ft_put_after(char *nbr, char c, int n);
int				ft_get_len(char *str, t_arg *elem, int sign);
void			ft_put_before(char *str, char c, int nb);
char			*ft_strnew(size_t size);
int				ft_scd_flag(int index, const char *str, int mod);
int				ft_which_scd_flag(const char *str, int i);
int				ft_get_ulen(char *str, t_arg *elem);

/*
** protos libft de base.
*/

int				ft_putchar(char c);
int				ft_putstr(const char *s);
int				ft_strlen(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
void			ft_bzero(void *s, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strdup(const char *src);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_itoa(intmax_t n);
char			*ft_strchr(const char *str, int n);
char			*ft_strrchr(const char *str, int n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_atoi(const char *str);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
void			*ft_memset(void *b, int c, size_t n);
void			*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void			*ft_memmove(void *s1, const void *s2, size_t n);
void			ft_putnbr(int n);
void			ft_putendl(const char *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			**ft_strsplit(const char *s, char c);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
int				ft_strequ(const char *s1, const char *s2);
char			*ft_strtrim(const char *s);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnstr(const char *big, const char *find, size_t len);
t_list			*ft_lstnew(const void *content, size_t content_size);
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstadd(t_list **alst, t_list *new);
void			*ft_memchr(const void *s, int c, size_t n);
char			*ft_itoa_base(intmax_t nb, char *base);
char			*ft_uitoa_base(uintmax_t nb, char *base);

/*
** protos get_next_line
*/

int				get_next_line(const int fd, char **line);

#endif
