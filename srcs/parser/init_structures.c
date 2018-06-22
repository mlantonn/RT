/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:12:55 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/20 20:08:00 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "vec.h"

void	init_cameras(t_data *data)
{
	int i;

	i = -1;
	while (++i < CAM_NB)
	{
		data->cams[i].pos = (t_vec){0, 0, 0};
		data->cams[i].angle = (t_vec){0, 0, 0};
		data->cams[i].fov = 70;
		get_vp_up_left(&data->cams[i]);
	}
}

void	init_one_light(t_data *data, int index)
{
	data->lights[index].is_para = 0;
	data->lights[index].disabled = 0;
	data->lights[index].r = 1;
	data->lights[index].ambi = 0.3;
	data->lights[index].pos = (t_vec){0.0, 0.0, 0.0};
	data->lights[index].dir = (t_vec){0.0, 0.0, 0.0};
	data->lights[index].color.c = 0xFFFFFFFF;
}

int		init_lights(t_data *data, int nb)
{
	int i;

	i = -1;
	if (!(data->lights = (t_light *)malloc(sizeof(t_light) * nb)))
	{
		perror("Error : ");
		return (-1);
	}
	while (++i < nb)
		init_one_light(data, i);
	return (0);
}

void	init_one_object(t_data *data, int index)
{
	data->objs[index].r = 100;
	data->objs[index].spec = 1;
	data->objs[index].alpha = 100;
	data->objs[index].color.c = get_color_gtk(255, 0xA6, 0, 0xA6);
	data->objs[index].pos = (t_vec){0, 0, 1500};
	data->objs[index].dir = (t_vec){1, 1, 0};
	data->objs[index].normal = (t_vec){1, 1, 0.001};
	data->objs[index].intersect = intersect_sphere;
	data->objs[index].get_normal = get_sphere_normal;
}

int		init_objects(t_data *data, int nb)
{
	int i;

	i = -1;
	if (!(data->objs = (t_obj *)malloc(sizeof(t_obj) * nb)))
	{
		perror("Error : ");
		return (-1);
	}
	while (++i < nb)
		init_one_object(data, i);
	return (0);
}
