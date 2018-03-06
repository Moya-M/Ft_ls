/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   file.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 14:28:49 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 16:33:38 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*ft_filedate(__darwin_time_t ftime)
{
	char	*tmp;
	char	*tmp2;
	char	*out;
	time_t	now;

	time(&now);
	if (now - 15778476 > ftime)
	{
		tmp = ft_strndup(ctime(&ftime) + 4, 7);
		if (!(tmp2 = ft_strndup(ctime(&ftime) + 19, 5)) || !tmp)
			return (NULL);
		out = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
	}
	else
		out = ft_strndup(ctime(&ftime) + 4, 12);
	if (!out)
		return (NULL);
	return (out);
}

char	*ft_cname(char *name, char *c)
{
	char	*out;
	char	*tmp;

	if (c[0] == 'd')
		out = ft_strjoin("\e[1;36m", name);
	else if (c[0] == 'l')
		out = ft_strjoin("\e[0;35m", name);
	else if (c[0] == '-' && c[9] == 'x')
		out = ft_strjoin("\e[0;31m", name);
	else if (c[0] == 'c')
		out = ft_strjoin("\e[0;34;43m", name);
	else if (c[0] == 'b')
		out = ft_strjoin("\e[0;34;46m", name);
	else if (c[0] == 'p')
		out = ft_strjoin("\e[0;33m", name);
	else
		out = ft_strdup(name);
	if (!out || !(tmp = out))
		exit (-1);
	if (!(out = ft_strjoin(out, "\e[0m")))
		exit (-1);
	ft_strdel(&tmp);
	return (out);
}
