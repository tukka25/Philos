/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:36:18 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/05 19:24:20 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*new_string;
	char	tmp;

	if (!s)
		return (NULL);
	tmp = (char ) c;
	while (*s != '\0')
	{
		if (*s == tmp)
		{
			new_string = (char *) s;
			return (new_string);
		}
		s++;
	}
	if (tmp == 0)
		return ((char *)s + ft_strlen(s));
	return (NULL);
}
