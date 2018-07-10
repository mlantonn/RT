/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:31:19 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/10 18:31:57 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
/*
** Theses global variable are only accessible by function on this file
 */

t_pixelbuf		*g_pxb;
t_color			g_color;
GtkWidget		*g_win_color;
GtkWidget		*g_img;

static void		ev_color_cancel(GtkWidget *widget, gpointer param)
{
	t_color		*prev_color;

	prev_color = (t_color*)param;
	g_color.c = prev_color->c;
	if (!widget && !param)
		return ;
	gtk_widget_destroy(g_win_color);
	pixelbuf_free(&g_pxb);
}

static void		ev_color_apply(GtkWidget *widget, gpointer param)
{
	t_color		*color;

	if (!widget && !param)
		return ;
	color = (t_color*)param;
	*color = g_color;
	color_widget_img(g_img, g_color);
	gtk_widget_destroy(g_win_color);
	pixelbuf_free(&g_pxb);
}

static void		scale_change_color(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;

	if (!widget && !param)
		return ;
	group = (GtkSizeGroup*)param;
	g_color.argb.a = 255;
	change_color_from_group(group, &g_color);
	fill_pixelbuf_in_color(g_pxb, g_color.c);
	put_pixelbuf_to_widget(g_pxb, NULL);
}

static t_color	get_color_of_img(GtkWidget *img)
{
	t_color			color;
	GdkPixbuf		*pxb;
	uint32_t		*pxl;

	pxb = gtk_image_get_pixbuf(GTK_IMAGE(img));
	pxl = (uint32_t*)gdk_pixbuf_get_pixels(pxb);
	color.c = pxl[0];
	return (color);
}

void			chose_color(GtkWidget *img, gpointer param)
{
	t_wid_data		wid_d;

	init_wid_data(&wid_d, 1, ptdb_set(0, 255));
	wid_d.f = &scale_change_color;
	g_img = img;
	g_color = get_color_of_img(img);
	add_color_choose(&wid_d, g_color);
	g_pxb = pixelbuf_new(pt_set(30, 30), NULL);
	fill_pixelbuf_in_color(g_pxb, g_color.c);
	wid_d.pos = pt_set(6, 0);
	wid_d.size = pt_set(2, 1);
	gtk_grid_attach(GTK_GRID(wid_d.grid), g_pxb->widget, wid_d.pos.y,
			wid_d.pos.x, wid_d.size.x, wid_d.size.y);
	wid_d.pos = pt_set(8, 0);
	wid_d.size = pt_set(1, 1);
	wid_d.f = &ev_color_apply;
	b_new(&wid_d, param, "apply", NULL);
	wid_d.pos = pt_set(8, 1);
	wid_d.f = &ev_color_cancel;
	b_new(&wid_d, (gpointer)img, "cancel", NULL);
	g_win_color = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(g_win_color), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(g_win_color), 200, 400);
	gtk_container_add(GTK_CONTAINER(g_win_color), wid_d.grid);
	gtk_widget_show_all(g_win_color);
}
