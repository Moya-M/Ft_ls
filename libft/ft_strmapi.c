/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:19:15 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 18:19:17 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		r[i] = (*f)(i, s[i]);
		i++;
	}
	r[i] = '\0';
	return (r);
}
