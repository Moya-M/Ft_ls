/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 14:47:25 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 21:16:29 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_opt	*ft_opt(void)
{
	t_opt *opt;

	opt = malloc(sizeof(t_opt));
	opt->j = 1;
	opt->ur = 0;
	opt->r = 0;
	opt->l = 0;
	opt->a = 0;
	opt->ug = 0;
	opt->t = 0;
	opt->blck = 0;
	return (opt);
}

t_opt	*ft_opthandler(char **av, int ac)
{
	t_opt	*opt;
	int		i;

	opt = ft_opt();
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
		}
		i = 0;
		opt->j++;
	}
	return (opt);
}

char	ft_optchecker(int ac, char **av)
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

int		main(int ac, char **av)
{
	char	c;
	int		i;
	t_opt	*opt;

	i = 0;
	if ((c = ft_optchecker(ac, av)))
	{
		ft_putstr("ls: illegal option -- ");
		ft_putchar(c);
		ft_putstr("\nusage: ls [-alrtGR] [file ...]\n");
		return (-1);
	}
	opt = ft_opthandler(av, ac);
	i += opt->j;
	if (i == ac)
		ft_filereadder(".", opt);
	else
		while (i < ac)
			ft_filereadder(av[i++], opt);
	free(opt);
	sleep(150000);
	return (0);
}
