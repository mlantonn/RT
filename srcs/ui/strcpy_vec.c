/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_vec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:31:12 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/29 12:01:04 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char		*strcpy_vec(char *str, t_vec vec)
{
	*str = '[';
	str++;
	str = strcpy_db(str, vec.x);
	*str = ',';
	str++;
	*str = ' ';
	str++;
	str = strcpy_db(str, vec.y);
	*str = ',';
	str++;
	*str = ' ';
	str++;
	str = strcpy_db(str, vec.z);
	*str = ']';
	str++;
	return(str);
}
