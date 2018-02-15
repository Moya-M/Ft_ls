/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putll.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 14:49:05 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 19:30:05 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_putll(long long l)
{
	char c;

	c = '0';
	if (l < 0)
	{
		write(1, "-", 1);
		l = -l;
	}
	if (l > 9)
	{
		ft_putll((l / 10));
		c += l % 10;
		write(1, &c, 1);
	}
	else
	{
		c += l;
		write(1, &c, 1);
	}
}

char	*ft_lltoa(off_t l)
{
	char	*str;
	int		i;
	int		neg;

	neg = 0;
	i = ft_countdigit(l);
	if (l < 0)
	{
		neg = 1;
		l *= -1;
	}
	i += neg;
	if (!(str = ft_strnew(i--)))
		return (NULL);
	if (l == 0)
		str[0] = '0';
	while (l > 0)
	{
		str[i--] = (l % 10) + '0';
		l /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
