/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:11:34 by asolis            #+#    #+#             */
/*   Updated: 2017/01/09 21:11:38 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE	9000

# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_tools
{
	int				hh;
	int				h;
	int				l;
	int				ll;
	int				jj;
	int				zz;
	int				i;
	int				j;
	int				k;
	int				fnb;
	int				res;
	int				len;
	int				temp;
	int				count;
	int				x;
	int				y;
	int				m;
	int				s;
	int				plus;
	int				dat;
	int				z;
	int				dat_nb;
	int				ht;
	int				percent;
	long int		decimalnumber;
	long int		quotient;
	char			hexadecimalnumber[100];
	char			*pluss;
	char			*tmp;
	char			*nb;
	char			*nb2;
	char			*str;
	char			*buff;
	char			c;
}					t_tools;

typedef struct		s_pf
{
	t_tools			t;
}					t_pf;

int					ft_putchar(int c);
void				ft_putchar_fd(char c, int fd);
void				ft_div_mod(int a, int b, int *div, int *mod);
int					ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_memdel(void **ap);
void				ft_generic(void);
void				ft_swap(int *a, int *b);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s1);
void				ft_putnbr(int nb);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putnbr_fd(int nb, int fd);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c,\
						size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strtrim(char const *s);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,\
						size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_itoa(int n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_strsplit(char const *s, char c);
size_t				ft_strlen(const char *s);
size_t				ft_strlennum(char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					get_next_line(const int fd, char **line);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_atoi(const char *str);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_sqrt(int nb);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_tolower(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_wclen(wchar_t wc);
int					ft_putwchar(wchar_t wc);
int					ft_putwstr(wchar_t *wcs);
int					ft_isspace(int c);
char				*ft_itoa_base(int n, int b);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
int					ft_printf(const char *format, ...);
int					ft_s_dat(t_pf *f, char *str);
int					ft_p(t_pf *f, va_list ap);
int					ft_s(t_pf *f, va_list ap);
int					ft_s_dat(t_pf *f, char *str);
int					ft_s_x(t_pf *f, char *str, int flag);
int					ft_c(t_pf *f, int c);
int					ft_i(t_pf *f, va_list pa);
int					ft_i_d(t_pf *f, char *str);
int					ft_i_x(t_pf *f, char *str);
int					ft_i_x_complex(t_pf *f, char *str);
int					ft_i_x_complex_1(t_pf *f, char *str);
int					ft_i_x_r(t_pf *f, char *str);
int					ft_x(t_pf *f, va_list pa);
int					ft_u(t_pf *f, va_list pa);
int					ft_o(t_pf *f, va_list pa);
int					resul_hex(t_pf *f);
int					ft_chose_format(t_pf *f, va_list pa);
char				*ft_itoa_basel(unsigned long long int value, int base);
char				*reverse_array(char *s);
void				zero(t_pf *f);

#endif