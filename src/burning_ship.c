/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:47:34 by ksura             #+#    #+#             */
/*   Updated: 2022/07/19 14:45:49 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	burning_ship(t_data *data, int x, int y)
{
	int		n;
	double	z_re;
	double	z_i;
	double	tmp;

	z_re = 0;
	z_i = 0;
	n = -1;
	data->is_in_set = 1.0;
	while (++n < data->max_ite)
	{
		if ((z_re * z_re + z_i * z_i) > 4.0)
		{
			data->is_in_set = 0.0;
			break ;
		}
		tmp = 2 * fabs(z_re * z_i) + data->z_i;
		z_re = z_re * z_re - z_i * z_i + data->z_re;
		z_i = tmp;
	}
	my_mlx_pixel_put(data, x, y, n);
}
