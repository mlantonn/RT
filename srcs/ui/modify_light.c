/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_parallel_light.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:59:20 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/07 14:32:34 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "parse.h"

void			switch_light(GtkWidget *widget, gpointer param)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)) == TRUE)
	{
		gtk_button_set_label(GTK_BUTTON(widget), "OFF");
		g_data->lights[g_data->ui->page_light].enabled = 0;
	}
	else
	{
		gtk_button_set_label(GTK_BUTTON(widget), "ON");
		g_data->lights[g_data->ui->page_light].enabled = 1;
	}
}

void			switch_parallel_light(GtkWidget *widget, gpointer param)
{
	GSList		*lst;
	gboolean	status;
	int			i;

	if (!param)
		return ;
	lst = gtk_size_group_get_widgets(GTK_SIZE_GROUP(param));
	i = g_data->ui->page_light;
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)) == TRUE)
	{
		gtk_button_set_label(GTK_BUTTON(widget), "OFF");
		status = FALSE;
		g_data->lights[i].is_para = 0;
	}
	else
	{
		gtk_button_set_label(GTK_BUTTON(widget), "ON");
		status = TRUE;
		g_data->lights[i].is_para = 1;
	}
	while (lst)
	{
		gtk_widget_set_sensitive(GTK_WIDGET((GtkWidget*)lst->data), status);
		lst = lst->next;
	}
}

void			add_one_light(GtkWidget *widget, gpointer param)
{
	t_light		*lights_new;
	int			i;

	i = -1;
	g_data->nb_lights += 1;
	lights_new = (t_light*)malloc(sizeof(t_light) * g_data->nb_lights);
	while (++i < (g_data->nb_lights - 1))
		lights_new[i] = g_data->lights[i];
	free(g_data->lights);
	g_data->lights = lights_new;
	init_one_light(g_data, i);
	add_one_light_tab(g_data->ui->tab_light, i);
	gtk_widget_show_all(g_data->win_gtk);
}

void			change_light_pos(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	t_vec			*vec;

	vec = &g_data->lights[g_data->ui->page_light].pos;
	group = (GtkSizeGroup*)param;
	change_vec_from_scale(group, vec);
}

void			change_light_dir(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	t_vec			*vec;

	vec = &g_data->lights[g_data->ui->page_light].dir;
	group = (GtkSizeGroup*)param;
	change_vec_from_scale(group, vec);
}
