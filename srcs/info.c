/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   info.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 14:19:34 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 14:12:23 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char	ft_filetype(mode_t st_mode)
{
	if (S_ISDIR(st_mode))
		return ('d');
	else if (S_ISLNK(st_mode))
		return ('l');
	else if (S_ISBLK(st_mode))
		return ('b');
	else if (S_ISCHR(st_mode))
		return ('c');
	else if (S_ISSOCK(st_mode))
		return ('s');
	else if (S_ISFIFO(st_mode))
		return ('p');
	return ('-');
}

static char	*ft_fileperm(struct stat fstat)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * 11)))
		return (NULL);
	str[0] = ft_filetype(fstat.st_mode);
	str[1] = (fstat.st_mode & S_IRUSR) ? 'r' : '-';
	str[2] = (fstat.st_mode & S_IWUSR) ? 'w' : '-';
	str[3] = (fstat.st_mode & S_IXUSR) ? 'x' : '-';
	str[4] = (fstat.st_mode & S_IRGRP) ? 'r' : '-';
	str[5] = (fstat.st_mode & S_IWGRP) ? 'w' : '-';
	str[6] = (fstat.st_mode & S_IXGRP) ? 'x' : '-';
	str[7] = (fstat.st_mode & S_IROTH) ? 'r' : '-';
	str[8] = (fstat.st_mode & S_IWOTH) ? 'w' : '-';
	if (fstat.st_mode & S_ISVTX)
		str[9] = (fstat.st_mode & S_IXOTH) ? 't' : 'T';
	else
		str[9] = (fstat.st_mode & S_IXOTH) ? 'x' : '-';
	str[10] = '\0';
	return (str);
}

static void	ft_listhandler(struct stat fstat, t_file *info, t_opt *opt)
{
	struct group	*grp;
	struct passwd	*psw;
	char			*lnk;

	if (!opt->l)
		return ;
	grp = getgrgid(fstat.st_gid);
	psw = getpwuid(fstat.st_uid);
	info->link = fstat.st_nlink;
	info->grp = psw == NULL ? ft_itoa(fstat.st_uid) : ft_strdup(psw->pw_name);
	info->usr = grp == NULL ? ft_itoa(fstat.st_gid) : ft_strdup(grp->gr_name);
	info->size = fstat.st_size;
	if (S_ISLNK(fstat.st_mode))
	{
		lnk = ft_strnew(PATH_MAX);
		readlink(info->rep, lnk, PATH_MAX);
		info->lnk = lnk;
	}
	else
		info->lnk = ft_strnew(0);
	if (!info->grp || !info->usr || !info->lnk)
		return ;
	info->dev = fstat.st_rdev;
}

t_file		*ft_fileinfo(const char *rep, char *name, t_opt *opt)
{
	struct stat		fstat;
	t_file			*info;

	info = malloc(sizeof(t_file));
	if (!(info->rep = ft_strnew(ft_strlen(rep) + ft_strlen(name) + 1)))
		return (NULL);
	info->rep = ft_strcat(info->rep, rep);
	info->rep = ft_strcat(info->rep, "/");
	info->rep = ft_strcat(info->rep, name);
	lstat(info->rep, &fstat);
	ft_listhandler(fstat, info, opt);
	if (!(info->perm = ft_fileperm(fstat)))
		return (NULL);
	info->stamp = fstat.st_mtimespec.tv_sec;
	info->date = ft_filedate(fstat.st_mtimespec.tv_sec);
	info->cname = opt->ug ? ft_cname(name, info->perm) : ft_strdup(name);
	info->name = ft_strdup(name);
	opt->blck += fstat.st_blocks;
	opt->max = opt->max > ft_countdigit(info->size) ?
	opt->max : ft_countdigit(info->size);
	if (!info->date || !info->cname || !info->name)
		return (NULL);
	return (info);
}
