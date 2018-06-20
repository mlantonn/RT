/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 03:13:41 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/20 00:02:03 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_vec	pitch(t_vec ray, t_vec angle)
{
	t_vec	axe;
	double	theta;

	axe = (t_vec) {ray.x, 0, 0};
	theta = (angle.x / 180.0) * M_PI;
	axe.y = ray.y * cos(theta) - ray.z * sin(theta);
	axe.z = ray.y * sin(theta) + ray.z * cos(theta);
	return (axe);
}

t_vec	yaw(t_vec ray, t_vec angle)
{
	t_vec	axe;
	double	theta;

	axe = (t_vec) {0, ray.y, 0};
	theta = (angle.y / 180.0) * M_PI;
	axe.x = ray.x * cos(theta) - ray.z * sin(theta);
	axe.z = ray.x * sin(theta) + ray.z * cos(theta);
	return (axe);
}

t_vec	compute_ray(t_vec vp)
{
	t_vec	ray;

	ray = vec_normalize(vec_substract(vp, g_data->cam.pos));
	ray = pitch(ray, g_data->cam.angle);
	ray = yaw(ray, g_data->cam.angle);
	return (ray);
}