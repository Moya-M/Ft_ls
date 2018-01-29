/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 17:41:58 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 17:42:05 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				i;
	int				n;
	unsigned long	r;

	i = 0;
	n = 1;
	r = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		r *= 10;
		r += str[i] - '0';
		i++;
	}
	if (r >= 9223372036854775807)
		return (n == -1 ? 0 : -1);
	return ((int)r * n);
}
