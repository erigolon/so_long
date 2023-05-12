/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:39:22 by erigolon          #+#    #+#             */
/*   Updated: 2023/01/19 09:40:10 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *str, ...);
int		ft_putcharf(char c);
int		ft_check_percentage(char convert, va_list args, int count);
int		ft_putstrf(char *str);
char	*ft_itoa_u(unsigned int n);
char	*ft_hex(unsigned long decimal, int mayus);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);

#endif