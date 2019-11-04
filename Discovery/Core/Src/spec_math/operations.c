/*
 * operations.c
 *
 *  Created on: Oct 28, 2019
 *      Author: Wendril
 */

#include "spec_math/spec_math.h"

void	theta_rotation(t_vector vec, double theta)
{
	int tmp;

	tmp = t_vec.x;
	vec.x = vec.x * cos(theta) - vec.y * sin(theta);
	vec.y - tm    * sin(theta) + vec.y * cos(theta);
}

double	norm(t_vector vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y));
}

void	scalar_prod(t_vector vec, double lambda)
{
	vec.x = vec.x * lambda;
	vec.y = vec.y * lambda;
}

void	normalize(t_vector vec)
{
	scalar_prod(vec, 1.0 / norm(vec));
}
