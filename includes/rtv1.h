/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 20:44:16 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/24 18:43:10 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	RTv1 is a school project designed to learn the basics of raytracing.
*/

#ifndef RTV1_H
# define RTV1_H

# include <pthread.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "structs.h"
# include "defines.h"
# include "keys.h"

/*
**	Drawing functions.
*/
void	draw_image(t_data *data, t_obj *objs, t_ray light);

/*
**	Functions used to initialize the different structures.
*/
void	t_mlx_init(t_mlx *mlx);
int		img_init(t_mlx *mlx);
void	data_init(t_data *data);

/*
**	Vector operations.
*/
t_vec	vec_add(t_vec u, t_vec v);
t_vec	vec_substract(t_vec u, t_vec v);
t_vec	vec_multiply(t_vec u, double t);

t_vec	get_sphere_normal(t_obj sphere);
t_vec	get_plane_normal(t_obj plane);
t_vec	vec_normalize(t_vec u);
double	get_length(t_vec u);
double	dot_product(t_vec u, t_vec v);

int		intersect_sphere(t_ray ray, t_obj sphere, double *t);
int		intersect_plane(t_ray ray, t_obj plane, double *t);
int		shadow_ray(t_obj *objs, t_ray light, int index);

/*
**	Frees everything that has to be freed.
*/
int		exit_all(t_data *data);

#endif
