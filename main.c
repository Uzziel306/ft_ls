#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <grp.h>
#include <pwd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

void	ft_swapchar(char **a, char **b)
{
	char *c;

	c = ft_strdup(*a);
	*a = ft_strdup(*b);
	*b = ft_strdup(c);
}

int		print_value(char *file)
{
	char date[36];
	struct stat fileStat;
	struct passwd *pw;
	struct group  *gr;

	if(stat(file, &fileStat) < 0)
			return 1;
	pw = getpwuid(fileStat.st_uid);
	gr = getgrgid(fileStat.st_gid);
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
	ft_printf("  %d %s  %s %d ", fileStat.st_nlink, pw->pw_name, gr->gr_name, fileStat.st_size);
	ft_printf("%s %s\n", ft_strsub(ctime(&fileStat.st_ctime), 4, 12), file);
	return (fileStat.st_blocks);
}

int			ft_lendir() //Len of directory
{
	struct dirent *pDirent;
	DIR *pDir;
	int i;

	pDir = opendir(".");
	i = 0;
	while ((pDirent = readdir(pDir)) != NULL)
	if(pDirent->d_name[0] != '.')
		i++;
	closedir(pDir);
	return (i);
}

void		ft_print_Matrix(char **matrix) //Print the matrix
{
	int j;

	j = 0;
	while(matrix[j] != NULL)
	{
		ft_printf("%10s", matrix[j]);
		j++;
	}
}

char		**ft_make_matrix(int size) // feed the matrix with the names of the files in a randoom way
{
	struct dirent *pDirent;
	DIR *pDir;
	int i;
	char **matrix;

	matrix = (char **)malloc(sizeof(char *) * (size + 1));
	pDir = opendir(".");
	i = 0;
	while ((pDirent = readdir(pDir)) != NULL)
		{
			if(pDirent->d_name[0] != '.')
				{
					matrix[i] = ft_strdup(pDirent->d_name);
					i++;
				}
		}
		matrix[i] = NULL;
	closedir(pDir);
	return (matrix);
}

void		ft_ls() // ls unix comand
{
	int i;
	int j;
	int flag;
	char **matrix;

	flag = 1;
	i = ft_lendir();
	matrix = ft_make_matrix(i);
	while (flag != 0)
	{
		flag = 0;
		while(matrix[j] != NULL)
		{
			if (matrix[j + 1] && ft_strcmp(matrix[j], matrix[j + 1]) > 0)
			{
				ft_swapchar(&matrix[j], &matrix[j + 1]); //swaping the names
				flag++;
			}
			j++;
		}
		j = 0;
	}
	ft_print_Matrix(matrix);
}



int main(int argc, char **argv)
{
	if (argc == 1)
		ft_ls();


	// print_value(argv[1]);
	return (0);
}
