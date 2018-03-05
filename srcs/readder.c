/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   readder.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 18:38:11 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 20:21:28 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	flagurhandler(t_list *begin, t_opt *opt)
{
	t_file	*info;

	opt->blck = 0;
	while (begin)
	{
		info = begin->content;
		if (info->perm[0] == 'd' &&
		(ft_strcmp(info->name, "\e[1;36m.\e[0m") != 0 &&
		ft_strcmp(info->name, "\e[1;36m..\e[0m") != 0) &&
		(ft_strcmp(info->name, ".") != 0 &&
		ft_strcmp(info->name, "..") != 0))
			file_reader(info->rep, opt);
		begin = begin->next;
	}
}

static int	printerror(const char *rep)
{
	if (errno == 20)
	{
		ft_putstr(rep);
		ft_putchar('\n');
		return (1);
	}
	ft_putstr("ft_ls: ");
	if (ft_strchr(rep, '/'))
		ft_putstr(ft_strrchr(rep, '/') + 1);
	else
		ft_putstr(rep);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putchar('\n');
	return (1);
}

static int	errorhandler(const char *rep, DIR *dir)
{
	struct stat	fstat;
	int			i;

	i = lstat(rep, &fstat);
	if (dir == NULL && i == 0)
	{
		printerror(rep);
		return (1);
	}
	if ((fstat.st_mode & S_IXUSR) == 0)
		return (1);
	if (dir == NULL)
		return (1);
	return (0);
}

static void	printcur(const char *rep, t_opt *opt)
{
	if (opt->dir > 1 || opt->dir == -1)
	{
		if (opt->dir == -1)
			ft_putchar('\n');
		ft_putstr(rep);
		ft_putstr(":\n");
	}
}

int			file_reader(const char *rep, t_opt *opt)
{
	struct dirent	*file;
	t_list			*begin;
	t_file			*info;
	DIR				*dir;

	dir = opendir(rep);
	begin = NULL;
	errno != 2 ? printcur(rep, opt) : 0;
	if (errorhandler(rep, dir))
	{
		if (dir != NULL)
			closedir(dir);
		return (-1);
	}
	while ((file = readdir(dir)) != NULL)
	{
		if (opt->a == 0 && file->d_name[0] == '.')
			continue ;
		info = ft_fileinfo(rep, file->d_name, opt);
		begin == NULL ? begin = ft_lstnew(info, sizeof(t_file)) :
		ft_lstsortadd(&begin, ft_lstnew(info, sizeof(t_file)), opt);
		free(info);
	}
	closedir(dir);
	ft_print(begin, opt);
	opt->dir = -1;
	opt->ur ? flagurhandler(begin, opt) : 0;
	ft_lstd(&begin, ft_infodel, opt);
	return (1);
}
