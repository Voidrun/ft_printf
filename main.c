/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 23:49:31 by fratke            #+#    #+#             */
/*   Updated: 2019/01/15 23:04:26 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		main(void)
{
	long double f = 1.42;
	ft_printf("mine: %Lf\n", f);
	printf("unix: %Lf\n", f);
}
