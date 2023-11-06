/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:24:14 by josorteg          #+#    #+#             */
/*   Updated: 2022/10/19 13:58:08 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdarg.h>
# include<stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_decide(unsigned char l, va_list args);
int	ft_wchar(char s);
int	ft_whe(unsigned long n, char *basec, int base);
int	ft_whep(unsigned long n);
int	ft_whex(unsigned int n);
int	ft_whexx(unsigned int n);
int	ft_wint(int n);
int	ft_wstr(char *str);
int	ft_wuint(unsigned int n);

#endif
