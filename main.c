#include "ft_ls.h"

void		start(t_ls *f)
{
	f->t.i = 0;
	f->t.j = 0;
	f->t.z = 0;
	f->t.r = 0;
	f->t.flag = 1;
	f->t.tb = 0;
	f->f.l = 0;
	f->f.r2 = 0;
	f->f.a = 0;
	f->f.r = 0;
	f->f.t = 0;
}

void			ft_swapchar(char **a, char **b)
{
	char		*c;

	c = ft_strdup(*a);
	*a = ft_strdup(*b);
	*b = ft_strdup(c);
	ft_memdel((void **)&c);
}

int				getting_all_blocks(char **matrix, t_ls *f)
{
	int i;
	struct	stat fileStat;
	int count;

	i = 0;
	count = 0;
	while (matrix[i] != NULL)
	{
		stat(matrix[i], &fileStat);
		count += fileStat.st_blocks;
		i++;
	}
	return (count);
}

int				print_permissions(struct	stat fileStat, char *file)
{
	if(stat(file, &fileStat) < 0)
			return 1;
	ft_printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
	ft_printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
	return (fileStat.st_blocks);
}

int				print_value(char *file, char *dir, char flag)
{
	char		date[36];
	struct	stat fileStat;
	struct	passwd *pw;
	struct	group  *gr;
	// printf("file = %s\n dir = %s\n", file, dir);
	if(stat(file, &fileStat) < 0)
			return 1;
	pw = getpwuid(fileStat.st_uid);
	gr = getgrgid(fileStat.st_gid);
	print_permissions(fileStat, file);
	ft_printf("  %d %s  %s %7d ", fileStat.st_nlink, pw->pw_name, gr->gr_name, fileStat.st_size);
	if (flag == 1)
		ft_printf("%s %s\n", ft_strsub(ctime(&fileStat.st_ctime), 4, 12), file);
	else if(flag == 0)
		ft_printf("%s %s\n", ft_strsub(ctime(&fileStat.st_ctime), 4, 12), dir);
	return (fileStat.st_blocks);
	ft_memdel((void **)&pw);
	ft_memdel((void **)&gr);
	ft_memdel((void **)&dir);
	ft_memdel((void **)&flag);
}


int				ft_lendir(char *file) //Len of directory
{
	struct	dirent *pDirent;
	DIR			*pDir;
	int			i;

	pDir = opendir(file);
	i = 0;
	while ((pDirent = readdir(pDir)) != NULL)
	if(pDirent->d_name[0] != '.')
		i++;
	closedir(pDir);
	return (i);
}

void			ft_print_Matrix(char **matrix, int flag, char **direction) //Print the matrix
{
	int			j;

	j = -1;
	if (flag == 1)
	{
		while(matrix[++j] != NULL)
			ft_printf("%s\n", matrix[j]);
	}
	else if (flag == 0)
	{
		while(matrix[++j] != NULL)
			print_value(matrix[j], direction[j], 1);
	}
	else if (flag == 2)
		{
			while(matrix[++j] != NULL)
				print_value(matrix[j], direction[j], 0);
		}
}

char			**ft_make_matrix(int size, char *file, int flag) // feed the matrix with the names of the files in a randoom way
{
	struct	dirent *pDirent;
	DIR 		*pDir;
	int 		i;
	char 		**matrix;

	matrix = (char **)malloc(sizeof(char *) * (size + 1));
	pDir = opendir(file);
	i = -1;
	while ((pDirent = readdir(pDir)) != NULL)
		{
			if(pDirent->d_name[0] != '.' && flag == 1)
				matrix[++i] = ft_strdup(pDirent->d_name);
			else
				matrix[++i] = ft_strdup(pDirent->d_name);
		}
		matrix[i] = NULL;
	closedir(pDir);
	// ft_print_Matrix(matrix);
	return (matrix);
}

char		**ft_ls(t_ls *f, char *file) // ls unix comand
{
	char **matrix;

	start(f);
	f->t.i = ft_lendir(file);
	matrix = ft_make_matrix(f->t.i, file);
	while (f->t.flag != 0)
	{
		f->t.flag = 0;
		while(matrix[f->t.j] != NULL)
		{
			if (matrix[f->t.j + 1] && ft_strcmp(matrix[f->t.j], matrix[f->t.j + 1]) > 0)
			{
				ft_swapchar(&matrix[f->t.j], &matrix[f->t.j + 1]); //swaping the names
				f->t.flag += 1;
			}
			f->t.j++;
		}
		f->t.j = 0;
	}
	return(matrix);
}

int				ft_getting_dir(char *file)
{
	struct	stat fileStat;

	stat(file, &fileStat);
	if(S_ISDIR(fileStat.st_mode))
		return(1);
	return (0);
	}

void			ft_ls_R(t_ls *f, char *file)
{
	char		**matrix;
	int			i;
	struct	stat fileStat;
	char		*tmp;

	i = -1;
	if ((ft_strcmp(file, ".") != 0))
		ft_printf("%s : \n", file);
	matrix = ft_ls(f, file);
	ft_print_Matrix(matrix, 1, f->t.matrix);
	while (matrix[++i] != NULL)
	{
		tmp = ft_strjoin(file, "/");
		f->t.tmp = ft_strjoin(tmp, matrix[i]);
		stat(f->t.tmp, &fileStat);
		if(S_ISDIR(fileStat.st_mode))
			{
				matrix[i] = ft_strdup(f->t.tmp);
				ft_printf("\n\n", file);
				ft_ls_R(f, matrix[i]);
			}
	}
	ft_memdel((void **)&matrix);
	ft_memdel((void **)&tmp);
}

void			ft_ls_l(t_ls *f, char *file)
{
	char		**matrix;
	char		**tmp;

	matrix = ft_ls(f, file);
	tmp = ft_ls(f, file);
	if (f->t.i != 1)
		ft_printf("total %d\n", getting_all_blocks(matrix, f));
	ft_print_Matrix(matrix, 0, tmp);
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&matrix);
}

char				**getting_direction(char **matrix, char *file,  t_ls *f)
{
	int i;
	char			*tmp;
	char			*tmp2;
	char			**tmp3;

	tmp3 = (char**)malloc(sizeof(char*) * (f->t.i + 1));
	tmp3[f->t.i] = NULL;
	i = 0;
	while (matrix[i] != NULL)
	{
		tmp = ft_strjoin(file, "/");
		tmp2 = ft_strjoin(tmp, matrix[i]);
		tmp3[i] = ft_strdup(tmp2);
		i++;
	}
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&tmp2);
	return (tmp3);
}

void			ft_ls_R_2(t_ls *f, char *file)
{
	char **matrix;
	int i;
	struct	stat fileStat;
	char **direction;

	i = -1;
	if ((ft_strcmp(file, ".") != 0))
		ft_printf("%s : \n", file);
	matrix = ft_ls(f, file);
	direction = getting_direction(matrix, file, f);
	ft_printf("total %d\n", getting_all_blocks(direction, f));
	ft_print_Matrix(direction, 2, matrix);
	while (direction[++i] != NULL)
	{
		stat(direction[i], &fileStat);
		if(S_ISDIR(fileStat.st_mode))
			{
				ft_printf("\n");
				ft_ls_R_2(f, direction[i]);
			}
	}
	ft_memdel((void **)&matrix);
	ft_memdel((void **)&direction);
}

int			menu(t_ls *f)
{
	if (f->f.l == 0 && f->f.r2 == 0 && f->f.a == 0 && f->f.r == 0 && f->f.t == 0)
		ft_print_Matrix(ft_ls(f, "."), 1, f->t.matrix);
	else if (f->f.l == 1 && f->f.r2 == 0 && f->f.a == 0 && f->f.r == 0 && f->f.t == 0)
		ft_ls_l(f, ".");
	else if (f->f.l == 0 && f->f.r2 == 1 && f->f.a == 0 && f->f.r == 0 && f->f.t == 0)
		ft_ls_R(f, ".");
	else if (f->f.l == 1 && f->f.r2 == 1 && f->f.a == 0 && f->f.r == 0 && f->f.t == 0)
		ft_ls_R_2(f, ".");
	return (0);
}

int			flags(int argc, char **argv, t_ls *f)
{
	int			i;
	char		**tmp;

	i = 0;
	while (argv[i] != NULL)
	{
		if ((ft_strcmp(argv[i], "-l")) == 0)
			f->f.l = 1;
		else if ((ft_strcmp(argv[i], "-R")) == 0)
			f->f.r2 = 1;
		else if ((ft_strcmp(argv[i], "-a")) == 0)
			f->f.a = 1;
		else if ((ft_strcmp(argv[i], "-r")) == 0)
			f->f.r = 1;
		else if ((ft_strcmp(argv[i], "-t")) == 0)
			f->f.t = 1;
		i++;
	}
	printf("%s\n", tmp);
	return (menu(f));
}

int			main(int argc, char **argv)
{
	t_ls	*f;
	char **direction;
	if(!(f = (t_ls*)malloc(sizeof(t_ls))))
		return (0);
	start(f);
	flags(argc, argv, f);
	ft_memdel((void **)&f);
	return (0);
}
