/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowazga <yowazga@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:36:58 by yowazga           #+#    #+#             */
/*   Updated: 2023/01/08 19:57:59 by yowazga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i ++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	str = (char *)malloc(ft_strlen_2(s1) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		len += 1;
		return (len);
	}
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_inter(char *s, long n, int i)
{
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	while (n)
	{
		s[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	long	nb;
	char	*str;

	i = 0;
	nb = n;
	i = ft_len(nb);
	str = malloc(i * sizeof(char ) + 1);
	if (!str)
		return (0);
	str[i--] = 0;
	if (nb == 0)
	{
		str[0] = 48;
		return (str);
	}
	ft_inter(str, nb, i);
	return (str);
}
