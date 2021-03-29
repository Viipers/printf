/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:00:22 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/05 16:24:29 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_set{
	int			i;
	int			n;
	int			nbchar_output;
	int			zero;
	int			without_pre;
	int			stock_star;
	int			first_star;
	int			af_point;
	int			first_afpoint;
}				t_set;

int				ft_printf(const char *str, ...);
void			trim_param(char *str, t_set *param, va_list ap);
void			right_align(char *str, t_set *param, va_list ap);
void			test_right(char *str, t_set *param, va_list ap, int glob);
void			test_alignpoint(char *str, t_set *param, int glob, void *value);
void			left_align(char *str, t_set *param, va_list ap);
void			zero_align(char *str, t_set *param, va_list ap);
void			test_point(char *str, t_set *param, void *value);
void			point(char *str, t_set *param, va_list ap);
void			star(char *str, t_set *param, va_list ap);
void			test_lesszero(char *str, t_set *param, void *value, int p_zero);
void			test_equalszero(char *str, t_set *param, void *value);
void			test_supzero(char *str, t_set *param, void *value);
void			print_percent(t_set *param);
void			arg_int(va_list ap, t_set *param);
void			arg_uint(va_list ap, t_set *param);
void			arg_char(va_list ap, t_set *param);
void			arg_string(va_list ap, t_set *param);
void			arg_void(va_list ap, t_set *param);
void			arg_uihex(va_list ap, t_set *param);
void			arg_uihexm(va_list ap, t_set *param);
void			put_space(int glob, int a, t_set *param);
void			ft_putnbr_count(int n, t_set *param);
void			ft_putchar_count(char c, t_set *param);
void			ft_putstr_count(char *s, t_set *param);
void			ft_putstrn_count(char *s, t_set *param, int glob);
void			ft_putultoh_count(unsigned long a, t_set *param);
void			ft_putunbr_count(unsigned int a, t_set *param);
void			ft_putuihex_count(unsigned int a, t_set *param);
void			ft_putuihexm_count(unsigned int a, t_set *param);

#endif
