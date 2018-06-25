/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 18:27:51 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/25 20:53:57 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

# include "rtv1.h"
# include "structs.h"
# include "defines.h"

/*
**	Functions for create User Interface and event associated
*/

/*
** Parent functions
 */
int				create_ui(void);
int				create_sub_notebook(t_ui *ui, int do_param);
int				create_toolbar(GtkWidget *v_box, t_ui *ui);
int				create_light_ui(GtkWidget *main_tab);
int				create_object_ui(GtkWidget *main_tab);
int				create_camera_ui(GtkWidget *main_tab);
int				create_options_ui(GtkWidget *main_tab);

/*
** tool used to create widget or group of widget
*/
void			check_ui_active(int start);
void			set_wid_data(t_wid_data *wid_d, t_point pos, t_point size,
				void (*f)(GtkWidget*, gpointer));
void			set_wid_data_scale(t_wid_data *wid_d, double step,
		t_ptdb min_max);
int				init_wid_data(t_wid_data *wid_d, double step, t_ptdb min_max);
t_widget_vec	*wid_vec_new(GtkSizeGroup *group, t_vec *vec);
GtkWidget		*switch_new(t_wid_data *wid_d, gpointer param, gboolean state,
		void (*f)(GtkWidget*, gboolean, gpointer));
GtkWidget		*tgb_new(t_wid_data *wid_d, gpointer param, const char *txt);
GtkWidget		*scale_new(t_wid_data *wid_d, gpointer param, gdouble value);
GtkWidget		*entry_new(t_wid_data *wid_d, gpointer param,  const char *txt);
GtkWidget		*b_new(t_wid_data *wid_d, gpointer param, const char *txt,
		GtkWidget *img);
GtkWidget		*l_new(t_wid_data *wid_d, const char *txt);
GtkWidget		*new_cb_type(t_wid_data *wid_d, gpointer param, int index);
GtkSizeGroup	*add_vector_choose(t_wid_data *wid_d, char *label, t_vec vec);
GtkSizeGroup	*add_color_choose(t_wid_data *wid_d, t_color color);
int				create_light_tab(GtkWidget *tab_light, int index);
int				create_object_tab(GtkWidget *tab_light, int index);
int				make_grid(t_wid_data *wid_d);
int				make_entry_and_scale(t_wid_data *wid_d, const char *txt,
			GtkSizeGroup *group, gdouble value);
int				make_label_and_entry(t_wid_data *wid_d, const char *txt,
			gdouble value);
int				make_label_and_scale(t_wid_data *wid_d, const char *txt,
			gdouble value);

/*
** basic tool
*/
int				get_int_obj_type(const char *type);
char			*get_str_obj_type(int type);

/*
** Simple function to handle number and string for specific matters 
*/
char			*join_int(char const *s1, int n);
size_t			size_int(int n);
size_t			size_double(double n);
size_t			size_vec(t_vec vec);
size_t			size_color(t_color color);
size_t			size_of_str_json(void);
char			*my_strcopy(char *dest, char const *src);
char			*strcpy_db(char *str, double n);
char			*strcpy_vec(char *str, t_vec vec);
char			*color_toa(char *str, t_color color);

/*
** function for handle user interface event :
** =>toolbar event
*/
void			click_open(GtkWidget *widget, gpointer param);
void			click_save(GtkWidget *widget, gpointer param);
void			click_export(GtkWidget *widget, gpointer param);
void			click_redraw(GtkWidget *widget, gpointer param);
void			entry_change_scale(GtkWidget *widget, gpointer param);
size_t			size_of_str_json(void);
char			*fill_object_json(char *str, int type, int i);
int				size_of_object_json(int size, int type, int i);
char			*fill_str_json(size_t size);
int				fill_widget_vec(t_widget_vec *dst, GtkSizeGroup *group,
		t_vec *vec);

/*
** => light event
*/
void			add_one_light(GtkWidget *widget, gpointer param);
void			change_light_pos(GtkWidget *widget, gpointer param);
void			change_light_dir(GtkWidget *widget, gpointer param);
void			change_light_r(GtkWidget *widget, gpointer param);
void			change_light_ambi(GtkWidget *widget, gpointer param);
void			switch_light(GtkWidget *widget, gboolean state, gpointer param);
void			switch_parallel_light(GtkWidget *widget, gboolean state,
		gpointer param);

/*
** => Object event
*/
void			add_one_obj(GtkWidget *widget, gpointer param);
void			change_obj_pos(GtkWidget *widget, gpointer param);
void			change_obj_angle(GtkWidget *widget, gpointer param);
void			switch_obj(GtkWidget *widget, gboolean state, gpointer param);
void			modify_obj_type(GtkWidget *widget, gpointer param);
void			change_obj_spec(GtkWidget *widget, gpointer param);

/*
** => Other UI event
*/
void			chose_color(GtkWidget *widget, gpointer useless);
gboolean		change_page_light(GtkNotebook *notebook, GtkWidget *page,
		gint arg1, gpointer data);
gboolean		change_page_cam(GtkNotebook *notebook, GtkWidget *page,
		gint arg1, gpointer data);
gboolean		change_page_obj(GtkNotebook *notebook, GtkWidget *page,
		gint arg1, gpointer data);
void			change_vec_from_scale(GtkSizeGroup *group, t_vec *vec);
void			change_color_from_group(GtkSizeGroup *group, t_color *color);
void			free_to_free(void *content);
#endif