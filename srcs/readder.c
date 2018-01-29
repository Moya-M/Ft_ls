/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   readder.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 18:38:11 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 14:53:56 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"
#include <string.h>

void	ft_flagurhandler(t_list *begin, t_opt *opt)
{
	t_file	*info;
	char	*rep;
	char	*tmp;

	opt->blck = 0;
	while (begin)
	{
		info = begin->content;
		if (info->perm[0] == 'd' &&
		(ft_strcmp(info->name, "\e[1;36m.\e[0m") != 0 &&
		ft_strcmp(info->name, "\e[1;36m..\e[0m") != 0) &&
		(ft_strcmp(info->name, ".") != 0 &&
		ft_strcmp(info->name, "..") != 0))
		{
			rep = ft_strjoin("\n", info->rep);
			tmp = rep;
			rep = ft_strjoin(rep, ":\n");
			ft_strdel(&tmp);
			write(1, rep, ft_strlen(rep));
			ft_strdel(&rep);
			ft_filereadder(info->rep, opt);
		}
		begin = begin->next;
	}
}

int		ft_printerror(const char *rep)
{
	write(1, "ft_ls: ", 8);
	if (ft_strchr(rep, '/'))
		write(1, ft_strrchr(rep, '/') + 1, ft_strlen(ft_strrchr(rep, '/') + 1));
	else
		write(1, rep, ft_strlen(rep));
	write(1, ": ", 2);
	write(1, strerror(errno), ft_strlen(strerror(errno)));
	write(1, "\n", 1);
	return (-1);
}

int		ft_filereadder(const char *rep, t_opt *opt)
{
	struct dirent	*file;
	t_list			*begin;
	t_file			*info;
	DIR				*dir;

	dir = opendir(rep);
	begin = NULL;
	if (dir == NULL)
		return (ft_printerror(rep));
	while ((file = readdir(dir)) != NULL)
	{
		if (opt->a == 0 && file->d_name[0] == '.')
			continue ;
		info = ft_fileinfo(rep, file->d_name, opt);
		if (begin == NULL)
			begin = ft_lstnew(info, sizeof(t_file));
		else
			ft_lstsortadd(&begin, ft_lstnew(info, sizeof(t_file)), opt);
		free(info);
	}
	closedir(dir);
	ft_print(begin, opt);
	opt->ur ? ft_flagurhandler(begin, opt) : 0;
	ft_lstd(&begin, ft_infodel, opt);
	return (1);
}
