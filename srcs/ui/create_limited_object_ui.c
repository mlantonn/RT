/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_limited_object_ui.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:49:06 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/14 18:43:15 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static int	phase_1(t_wid_data *wid_d, t_obj *obj, gboolean is_limited)
{
	GtkWidget		*sw;
	GtkSizeGroup	*group[2];

	if (!(l_new(wid_d, "limited object")))
		return (0);
	wid_d->f = &modify_obj_limited_type;
	wid_d->pos.y = 2;
	if (!(g_ui->cb_obj_limit = new_cb_limited(wid_d, obj, obj)))
		return (0);
	wid_d->pos = pt_set(wid_d->pos.x + 1, 0);
	wid_d->entry_f = &change_obj_min;
	if (!(group[0] = add_vector_choose_no_scale(wid_d, "min", obj->min)))
		return (0);
	wid_d->pos = pt_set(1, 2);
	wid_d->entry_f = &change_obj_max;
	if (!(group[1] = add_vector_choose_no_scale(wid_d, "max", obj->max)))
		return (0);
	return (1);
}

int		create_limited_object_ui(t_wid_data *wid_d, t_obj *obj)
{
	gboolean		is_limited;
	GtkWidget 		*frame;
	t_wid_data		frame_d;
	t_point			crd;
	GtkWidget 		*sw;


	is_limited = obj->limited == -1 ? FALSE : TRUE;
	if (!(frame = gtk_frame_new(NULL)))
		return (0);
	init_wid_data(&frame_d, wid_d->step, wid_d->min_max);
	if (!(phase_1(&frame_d, obj, is_limited)))
		return (0);
	wid_d->pos.y = 1;
	g_ui->is_active = 1;
	if (!(sw = switch_new(wid_d, (gpointer)frame_d.grid, is_limited, &switch_obj_limited)))
		return (0);
	if (is_limited == FALSE)
		switch_obj_limited(sw, FALSE, (gpointer)frame_d.grid);
	g_ui->is_active = 0;
	gtk_container_add(GTK_CONTAINER(frame), frame_d.grid);
	gtk_grid_attach(GTK_GRID(wid_d->grid), frame, 0, wid_d->pos.x, 4, 7);
	wid_d->pos.x += 7;
	return (1);
}
