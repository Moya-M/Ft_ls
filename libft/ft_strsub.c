/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:20:55 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 18:20:55 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	int		j;

	i = (int)start;
	j = 0;
	if (!(str = malloc(len + 1)) || !s)
		return (NULL);
	while (s[i])
		str[j++] = s[i++];
	str[len] = '\0';
	return (str);
}
