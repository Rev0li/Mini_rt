/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_atonbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:20:02 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/19 14:37:49 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	safe_atoi(const char *str, int *dest)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	if (*str < '0' || *str > '9')
		return (1);
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str++ - '0');
		if ((n * sign) > 2147483647 || (n * sign) < -2147483648)
			return (1);
	}
	if (*str != '\0')
		return (1);
	*dest = (int)(n * sign);
	return (0);
}
