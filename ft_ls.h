#ifndef FT_LS_H
# define FT_LS_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <grp.h>
#include <pwd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

typedef struct		s_tols
{
	int				i;
	int				j;
	int				z;
	int				tb;
	int				flag;
	int				r;
	char			*str;
	char			**matrix;
}					t_tols;

typedef struct		s_ls
{
	t_tols			t;
}					t_ls;

#endif
