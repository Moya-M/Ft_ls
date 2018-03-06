/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 14:47:25 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 17:04:56 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_opt	*opt_init(void)
{
	t_opt *opt;

	if (!(opt = malloc(sizeof(t_opt))))
		return (NULL);
	opt->j = 1;
	opt->ur = 0;
	opt->r = 0;
	opt->l = 0;
	opt->a = 0;
	opt->ug = 0;
	opt->t = 0;
	opt->max = 0;
	opt->blck = 0;
	opt->dir = 0;
	return (opt);
}

t_opt	*opt_handler(char **av, int ac)
{
	t_opt	*opt;
	int		i;

	if (!(opt = opt_init()))
		return (NULL);
	i = 0;
	if (ac == 1)
		return (opt);
	while (opt->j < ac && av[opt->j][0] == '-' && av[opt->j][1] != '\0'
		&& av[opt->j][1] != '-')
	{
		while (av[opt->j][i++])
		{
			av[opt->j][i] == 'G' ? opt->ug = 1 : 0;
			av[opt->j][i] == 'R' ? opt->ur = 1 : 0;
			av[opt->j][i] == 'r' ? opt->r = 1 : 0;
			av[opt->j][i] == 'l' ? opt->l = 1 : 0;
			av[opt->j][i] == 'a' ? opt->a = 1 : 0;
			av[opt->j][i] == 't' ? opt->t = 1 : 0;
		}
		i = 0;
		opt->j++;
	}
	return (opt);
}

char	opt_checker(int ac, char **av)
{
	int		i;
	int		j;
	char	*flag;

	i = 1;
	j = 0;
	flag = "RrlaGt";
	while (i < ac)
	{
		while (av[i][j++] && av[i][0] == '-')
			if (ft_strchr(flag, av[i][j]) == NULL && av[i][j] != '\0')
				return (av[i][j]);
		j = 0;
		i++;
	}
	return (0);
}

int		arghandler(char **av, int i, int ac, t_opt *opt)
{
	DIR		*dir;

	while (i < ac)
	{
		opt->dir++;
		dir = opendir(av[i]);
		if (dir != NULL)
			closedir(dir);
		else if (errno == 2)
		{
			ft_putstr("ft_ls: ");
			ft_putstr(av[i]);
			ft_putstr(": ");
			ft_putstr(strerror(errno));
			ft_putchar('\n');
		}
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	char	c;
	int		i;
	t_opt	*opt;

	i = 0;
	if ((c = opt_checker(ac, av)))
	{
		ft_putstr("ls: illegal option -- ");
		ft_putchar(c);
		ft_putstr("\nusage: ls [-alrtGR] [file ...]\n");
		return (1);
	}
	if (!(opt = opt_handler(av, ac)))
		return (-1);
	i += opt->j;
	arghandler(av, i, ac, opt);
	if (i == ac)
		file_reader(".", opt);
	else
	{
		while (i < ac)
			file_reader(av[i++], opt);
	}
	free(opt);
	sleep(500);
	return (0);
}
