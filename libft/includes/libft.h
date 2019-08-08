/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:31:00 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/05 21:56:26 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "debug.h"
# include <string.h>

# define NONE 0
# define VERBOSE 1

# define ABS(x) (x < 0 ? -x : x)

/*
** Mask macro
*/

# define LOWER (2 << 0)
# define UPPER (2 << 1)
# define HEXA (2 << 2)
# define HEXA_UPPER (2 << 3)

/*
** Hash macro
*/

# define HASH_ADD(hash,stuff) hash = ft_hashadd(hash, stuff)
# define HASH_INT(key,value) ft_hashnew(key, &value, type_int, sizeof(int))
# define HASH_CHAR(key,value) ft_hashnew(key, &value, type_char, sizeof(char))
# define HASH_ADDR(k,v) ft_hashnew(k, v, type_addr, sizeof(void *))
# define HASH_STR(k,v) ft_hashnew(k, v, type_str, ft_strlen(k))
# define HASH_LIST(k,v,s) ft_hashnew(k, v, type_lst, s)
# define HASH_TAB(k,v) ft_hashnew(k, v, type_tab, ft_tablen(v))

/*
** Arg macro
*/

# define ARG_INVALID_OPTION (2 << 0)
# define ARGFIND_STOP_FALSE (2 << 3)
# define ARGFIND_STOP_FIRST (2 << 2)
# define ARGFIND_ALL (2 << 1)
# define ARGFIND_RET_INDEX (2 << 0)

/*
** Linked list struct
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Hash types enum
*/

typedef enum		e_type
{
	type_int,
	type_char,
	type_addr,
	type_str,
	type_tab,
	type_lst
}					t_type;

/*
** Hash struct
*/

typedef struct		s_hash
{
	char			*key;
	void			*value;
	t_type			type;
	size_t			size;
	struct s_hash	*next;
	struct s_hash	*prev;
	struct s_hash	*first;
}					t_hash;

/*
** Color enumeration
*/

# ifndef LIBFT_COLOR
#  define LIBFT_COLOR

typedef enum		e_color
{
	red,
	bourg,
	white,
	blue,
	dark,
	purple,
	cyan,
	yellow,
	green,
	pink,
	end_color
}					t_color;

# endif

/*
** Arg struct
*/

typedef struct		s_arg
{
	int				argc;
	int				sum;
	char			**argv;
	char			**arglist;
	int				error_sum;
	char			*error;
	char			*(*fetch)(struct s_arg *, char *);
	int				(*check)(struct s_arg *, char *);
	void			(*get_error)(struct s_arg *);
	void			(*arg_add)(struct s_arg *, char *);
	char			**(*none)(struct s_arg *);
}					t_arg;

/*
** Tab functions
*/

char				**ft_tabinit(size_t size);
char				**ft_tabadd(char **tab, char *s);
char				**ft_tabdel(char **tab, int index);
void				ft_tabfree(char ***tab);
char				**ft_tabreplace(char **tab, char *s, int index);
int					ft_tabfind(char **tab, char *s);
int					ft_tabcount(char **tab);
char				**ft_tabslip(char **tab, char *s, int index);
int					ft_tablen(char **tab);
char				**ft_tabdup(char **tab);
void				ft_tabprint(char **tab);
void				ft_tabprint_fd(char **tab, int fd);
char				**ft_tabnew(size_t col);
char				**ft_tabjoin(char **tab1, char **tab2);

/*
** Hash functions
*/

t_hash				*ft_hashnew(char *key, void *d, t_type type, size_t size);
t_hash				*ft_hashadd(t_hash *old, t_hash *new);
void				ft_hashprint(t_hash *hash, int index);
void				ft_hashprintendl(t_hash *hash, int index);
void				ft_hashprint_all(t_hash *hash);
void				ft_hashfree(t_hash **hash);
void				ft_hashfree_allocated(t_hash **hash);
void				ft_hashdebug(t_hash *hash);
void				ft_hashfree_value(t_hash *hash);
int					ft_hashfind(t_hash **hash, char *key);
int					ft_hashdel(t_hash **hash, char *key);
void				ft_print_t_type(t_type type);

/*
** Arg Functions
*/

int					ft_argcheck_fun(t_arg *arg, char *s);
char				*ft_argfetch_fun(t_arg *arg, char *s);
int					ft_argcheck(char *arg, char **arglist, int sum);
char				*ft_argfetch(int argc, char **argv, char *arg);
int					ft_argsum(int argc, char **argv, char **arglist);
int					ft_argfind(char *argv, char *arglist, int mask);
t_arg				*ft_argnew(int argc, char **argv, char *argliststr);
void				ft_argfree(t_arg **arg);
int					ft_isarg(char *arg);
void				ft_argerror(t_arg *arg);
void				ft_argadd(t_arg *arg, char *s);
char				**ft_argnone(t_arg *arg);
int					ft_argsearch(char *argv, char **alst);

/*
** String operations
*/

int					ft_strisdigit(char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strclen(char *s, int n);
int					ft_strnchar(char *s, int n);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
int					ft_strcfind(const char *s, int n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strsubi(char const *s, int start, int end);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtjoin(char *s1, char *s2, char *s3);
char				*ft_strjoin_free(char **s, char const *s2);
char				*ft_strtrim(char *s);
char				**ft_strsplit(char const *s, char c);
char				**ft_strfsplit(char const *s, int (*f)(char));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strdup_free(char *s);
char				*ft_strsub_free(char *s, size_t start, size_t len);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strdel(char **as);
void				ft_strclr(char *s);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_swap_s(char **s1, char **s2);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_sub(char *s, int start, int end);
char				*ft_epur(char *s);

/*
** Check operations
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(char c);

/*
** Linked list operations
*/

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Memory operations
*/

int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
long				ft_byteswap(long num);

/*
** Number operations
*/

long long			ft_atob(const char *str, int base);
int					ft_isbase(int n, int base);
char				ft_getbase(int n);
char				ft_basechar(int n, int upper);
char				*ft_btoa(long long n, int base, int mask);
char				*ft_ltoa(long n);
int					ft_atoi(const char *str);
size_t				ft_numsize(long long num, unsigned int base);
char				*ft_itoa(int n);

/*
** Print operations
*/

void				ft_puthex(long n);
void				ft_putbase(long n, int base);
void				ft_putbin(long n);
void				ft_put_color(t_color color);
void				ft_put_color_fd(int fd, t_color color);
void				ft_end_color(void);
void				ft_end_color_fd(int fd);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_putnbrendl(int n);
void				ft_putcnbr(int n, t_color color);
void				ft_putcnbrendl(int n, t_color color);
void				ft_putcnbr_fd(int n, int fd, t_color color);
void				ft_putcnbrendl_fd(int n, int fd, t_color color);
void				ft_putlong(long n);
void				ft_putlongendl(long n);
void				ft_putendl(char const *s);
void				ft_putchar(int c);
void				ft_putchar_fd(int c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putdstr(char *s1, char *s2);
void				ft_putdendl(char *s1, char *s2);
void				ft_putdstr_fd(char *s1, char *s2, int fd);
void				ft_putdendl_fd(char *s1, char *s2, int fd);
void				ft_putcstr(char *s, t_color color);
void				ft_putcstr_fd(char *s, int fd, t_color color);
void				ft_putcendl(char *s, t_color color);
void				ft_putcendl_fd(char *s, int fd, t_color color);
void				ft_putendltab(char *s);
int					ft_error(char *error);
int					ft_error_file(char *error, char *file);
int					ft_error_verbose(char *err, char *reason);
char				*ft_projname(char *projname);
void				ft_print_list(int *l, unsigned int size);
void				ft_printaddr(void *addr);
void				ft_debugaddr(char *s, void *addr);

/*
** Double linked list operations
*/

/*
** List operations
*/

/*
** List tab operations
*/

/*
** To sort
*/

int					ft_retint_free(int fd, char **s, char ***tab, void **data);
void				*ft_retptr_free(int fd, char **s, char ***tab, void **data);
int					ft_send(char *s, int socket);
int					ft_sendendl(char *s, int socket);
void				ft_csend(char *s, t_color color, int co);

#endif
