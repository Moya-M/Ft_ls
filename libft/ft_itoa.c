/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:15:51 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 18:15:53 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int		count(long n)
{
	long i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	l;
	int		neg;

	neg = 0;
	l = n;
	i = count(l);
	if (l < 0)
	{
		neg = 1;
		l *= -1;
	}
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
