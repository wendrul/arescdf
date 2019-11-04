/*
 * odometrie.c
 *
 *  Created on: Oct 28, 2019
 *      Author: Wendril
 */

#include "spec_math/spec_math.h"
#include "robot/robot_specs.h"

int	update_position(t_vect dir, double delta_droite, double delta_gauche, double delta_time)
{
	double theta;

	theta = tan((delta_gauche - delta_droite) / WHEEL_SEPARATION_DISTANCE);
	theta_rotation(dir, theta);
	normalize(dir);
	
}
