/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 19:55:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/22 20:27:05 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdint.h>
# include "defines.h"
# include "mygtk.h"

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;
/*
**	Storing 3D coordinates or 3D vectors.
*/

typedef union		u_color
{
	uint32_t		c;
	struct			s_argb
	{
		uint8_t		r;
		uint8_t		g;
		uint8_t		b;
		uint8_t		a;
	}				argb;
}					t_color;
/*
**	Usage of an union for easy color management.
*/

typedef struct		s_added
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_added;
/*
**	To add colors.
*/

typedef struct		s_inter
{
	int				obj_i;
	double			t1;
	double			t2;
	double			t;
	double			delta;
	double			min_dist;
	t_color			spec;
	t_vec			ip;
	t_vec			normal;
	t_vec			oc;
	t_vec			origin;
}					t_inter;
/*
**	Intersection structure -> obj_i is the object index used to know which
**	object was intersected ; t1, t2 and delta are used for equations of degree
**	two, and t is the smallest positive number between t1 and t2 ; min_dist =
**	minimum distance before we consider there is an intersection ; spec =
**	specular shading at the intersection point ; ip = intersection point ;
**	normal = the normal of the object at 'ip' ; oc = vector between origin of
**	the current ray and center of the current object.
*/

typedef struct		s_camera
{
	t_vec			pos;
	t_vec			angle;
	t_vec			vp_up_left;
	double			vp_dist;
	double			fov;
}					t_camera;
/*
**	Cam struct -> pos = position ; angle = angle of vue ; vp_up_left = point at
**	the top left of the view_place ; vp_dist = distance between the camera and
**	the view plane ; fov = field of view.
*/

typedef struct		s_light
{
	int				is_para;
	int				disabled;
	double			r;
	double			ambi;
	t_vec			pos;
	t_vec			dir;
	t_color			color;
}					t_light;
/*
**	Cam struct -> is_para = 0 or 1 wether the light source is parallel or not ;
**	r = radius of the light source ; pos = position ; dir = direction.
*/

typedef struct s_obj	t_obj;
typedef struct		s_limit
{
	int				is_limited;
	double			min;
	double			max;
	t_vec			axe_min;
	t_vec			axe_max;
	t_vec			x;
	t_vec			y;
	int				(*limit)(struct s_obj, t_vec, t_inter *);
}					t_limit;
/*
**	Limit structure, with min and max lengths either on the direction axe or
**	the primary axe (x, y, z). x and y are vectors stored to avoid having to
**	calculate them for each plane intersection.
*/

struct				s_obj
{
	double			r;
	double			spec;
	double			alpha;
	t_color			color;
	t_vec			pos;
	t_vec			dir;
	t_vec			oc;
	t_vec			normal;
	t_limit			limit;
	int				obj_type;
	int				(*intersect)(struct s_obj, t_vec, t_inter *);
	t_vec			(*get_normal)(struct s_obj, t_inter);
};
/*
**	Object structure -> r = radius ; spec = specular coefficent for Phong
**	shading ; pos = position which defines the object ; dir = direction in
**	case it has one ; oc = vector between the current camera and 'pos' ;
**	normal = surface normal in case it's constant (e.g. plane)
*/

typedef struct		s_ui
{
	GtkWidget	*tab;
	t_list		*to_free;
	GtkWidget	*tab_light;
	GtkWidget	*tab_cams;
	GtkWidget	*tab_objs;
	int			is_active;
	int			page_light;
	int			page_cams;
	int			page_objs;
}					t_ui;

typedef struct		s_data
{
	int				nb_objects;
	t_obj			*objs;
	int				nb_lights;
	int				nb_lights_on;
	t_light			*lights;
	int				i;
	t_camera		cams[CAM_NB];
	t_camera		cam;
	int				px;
	int				aa;
	int				(*intersect[4])(struct s_obj, t_vec, t_inter *);
	t_vec			(*get_normal[4])(struct s_obj, t_inter);
	void			*win;
	t_pixelbuf		*img;
	t_ui			*ui;
	int				draw;
}					t_data;
/*
**	Struct used to store objects, light sources, and the 4 possible cameras, in
**	addition with the mlx struct;
*/

t_data				*g_data;
/*
**	Global variable of the data structure.
*/

typedef struct		s_funar_keyb
{
	int				key;
	void			(*f)(t_data*);
}					t_funar_keyb;
/*
** This structure is used to handle the keyboard event
** fill f with the function you want to use when the key is pushed
*/
typedef struct		s_wid_data
{
	t_point			pos;
	t_point			size;
	GtkWidget		*grid;
	void			(*f)(GtkWidget*, gpointer);
}					t_wid_data;
/*
** This structure is used to make widget, position it to a grid
** and link to function
*/

typedef struct		s_widget_vec
{
	GtkSizeGroup	*group;
	t_vec			*vec;
}					t_widget_vec;
#endif
