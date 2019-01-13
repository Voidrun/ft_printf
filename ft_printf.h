/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:52:34 by fratke            #+#    #+#             */
/*   Updated: 2019/01/13 15:53:02 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <string.h>

int		ft_printf(char *fmt, ...);
int		ft_putstr_f(char *str, int params[10]);
int		ft_putstr_fw(int *str, int params[10]);
int		ft_putnbr_base_f(long long int nbr, char *base);
int		ft_putnbr_base_fu(unsigned long long nbr, char *base);
int		ft_putchar_f(char c, int params[10]);

int		ft_putnbr_w(va_list *ap, int params[10]);
int		ft_putptr_w(va_list *ap, int params[10]);
int		ft_putchar_w(va_list *ap, int params[10]);
int		ft_putstr_w(va_list *ap, int params[10]);
int		ft_putnbr_uw(va_list *ap, int params[9]);
int		ft_putfloat_w(va_list *ap, int par[9]);
int		ft_strlen_w(int *str);
int		ft_putdef(char **str, int par[9]);
char	*ft_itoa_f(int nbr);
char	*get_sign(char **nstr, int par[9]);
char	*get_prec(int len, int par[9]);
char	*get_width(int len, int par[9]);
void    parse_format(char **fmt, int par[10], va_list *ap);

#endif
