/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sub_notebook.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 19:23:33 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/20 18:52:08 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		create_sub_notebook(t_ui *ui)
{
	g_data->ui->is_active = 0;
	if (!(create_light_ui(ui->tab)))
		return (0);
	if (!(create_camera_ui(ui->tab)))
		return (0);
	if (!(create_object_ui(ui->tab)))
		return (0);
	g_data->ui->is_active = 1;
	return (1);
}