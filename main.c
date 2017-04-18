#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <grp.h>
#include <pwd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int		print_value(char *file)
{
	char date[36];
	struct stat fileStat;
	struct passwd *pw;
	struct group  *gr;

	if(stat(file, &fileStat) < 0)
			return 1;
	// printf("-%s-\n", ctime(&fileStat.st_ctime));
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

int main(int argc, char **argv)
{
	static int i;
	struct dirent *pDirent;
	DIR *pDir;

	pDir = opendir(".");
	i = 0;
	if(argc != 2)
		return (1);
	while ((pDirent = readdir(pDir)) != NULL)
		print_value(pDirent->d_name);
	// print_value(argv[1]);
	return (0);
}
