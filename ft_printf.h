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
