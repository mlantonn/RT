/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_change_scale.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:15:17 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/18 18:51:40 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	entry_change_scale(GtkWidget *widget, gpointer param)
{
	GtkWidget	*scale;
	double		value;

	if (!param)
		return ;
	if (g_data->ui->is_active == 0)
		return ;
	scale = (GtkWidget*)param;
	value = ft_atof(gtk_entry_get_text(GTK_ENTRY(widget)));
	gtk_range_set_value(GTK_RANGE(scale), value);
}