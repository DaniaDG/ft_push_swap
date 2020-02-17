/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:51:12 by bsausage          #+#    #+#             */
/*   Updated: 2019/09/06 18:51:16 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"
#include "libft.h"

static long		check_overlong(long long n)
{
	if (n > (long long)LONG_MAX)
		return(LONG_MAX);
	if (n < (long long)LONG_MIN)
		return (LONG_MIN);
	return ((long)n);
}

long			ft_strtol(const char *str, char **end)
{
	int				i;
	int				sign;
	long long		result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]) && str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
		result = result * 10 + (str[i++] - '0');
	if (end)
		*end = (char*)&str[i];
	return (check_overlong(result * sign));
}
