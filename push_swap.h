/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:06:20 by yrigny            #+#    #+#             */
/*   Updated: 2023/12/18 12:04:05 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "printf.h"
# include "libft.h"

typedef struct s_list
{
	int	data;
	s_list	*last;
	s_list	*next;
}		t_list;


