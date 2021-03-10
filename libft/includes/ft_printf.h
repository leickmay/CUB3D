/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 08:47:07 by leickmay          #+#    #+#             */
/*   Updated: 2021/01/09 13:38:41 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_flags
{
	int		minus;
	int		zeros;
	int		dot;
	int		star;
	int		width;
	char	type;
}				t_flags;

int				is_in_flags(char c);
int				get_digit(char *str, int i, t_flags *flag);
int				get_dot(char *str, int i, t_flags *flag);
void			get_star(char *str, int i, t_flags *flag);
int				parse_flags(char *str, int i, t_flags *flag);
int				set_type(char *str, int i, t_flags *flag);
int				ft_find_width(t_flags *flag, va_list ap);
int				ft_find_dot(t_flags *flag, va_list ap);
char			*ft_strjoin_minus(char *new_nb, char *nb);
char			*ft_itoa_unsigned_int(unsigned int nb);
char			*ft_itoa_base_seize(size_t nb, char *base);
int				ft_print_c_width(int width, t_flags *flag, va_list ap);
int				ft_print_c(t_flags *flag, va_list ap);
int				ft_print_s_width(int width, char *str, t_flags *flag);
int				ft_print_s_dot(int width, int dot, char *str, t_flags *flag);
int				ft_find_dot_s(t_flags *flag, va_list ap);
int				ft_print_s(t_flags *flag, va_list ap);
int				ft_print_p_width(int width, char *nb, t_flags *flag);
int				ft_print_p_dot(int width, int dot, char *nb, t_flags *flag);
int				ft_print_p(t_flags *flag, va_list ap);
int				ft_print_d_width(int width, char *nb, t_flags *flag);
int				ft_print_d_dot_more(int width, int dot,
				char *nb, t_flags *flag);
int				ft_print_d_dot(int width, int dot, char *nb, t_flags *flag);
int				ft_print_d_zeros_more(int width, char *nb, t_flags *flag);
int				ft_print_d_zeros(int width, char *nb, t_flags *flag);
char			*fill_zeros(int width, int count, char *new_nb);
int				ft_print_d(t_flags *flag, va_list ap);
int				ft_print_u(t_flags *flag, va_list ap);
int				ft_print_x(t_flags *flag, va_list ap);
int				ft_print_big_x(t_flags *flag, va_list ap);
int				ft_print_percent_width(int width, t_flags *flag, char c);
int				ft_print_percent_zeros(int width, char c);
int				ft_print_percent(t_flags *flag, va_list ap);
t_flags			flags_init(t_flags flag);
int				ft_print_conversion(t_flags *flag, va_list ap);
int				treat_str(char *str, va_list ap);
int				ft_printf(const char *format, ...);
char			*ft_strjoin_free(char const *s1, char const *s2);

#endif
