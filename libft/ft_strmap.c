/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:19:12 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 18:19:14 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*r;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(r = malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		r[i] = (*f)(s[i]);
		i++;
	}
	r[i] = '\0';
	return (r);
}
