/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <giuliafanelli111@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:15:28 by gifanell          #+#    #+#             */
/*   Updated: 2025/01/20 17:22:35 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

int	ft_printf(const char *str, ...);

int	ft_putchar(char c);

int	ft_putstr(char *s);

int	ft_putnbr(int nb);

int	ft_uputnbr(unsigned int nb);

int	ft_puthex(unsigned long n, bool is_lower);

int	ft_putptr(unsigned long ptr);

#endif
