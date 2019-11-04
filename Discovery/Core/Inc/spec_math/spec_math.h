/*
 * spec_math.h
 *
 *  Created on: Oct 28, 2019
 *      Author: Wendril
 */

#ifndef INC_SPEC_MATH_SPEC_MATH_H_
#define INC_SPEC_MATH_SPEC_MATH_H_

#include <math.h>

typedef struct	s_vector
{
	double x;
	double y;
}		t_vector;


void	theta_rotation(t_vector vec, double theta);
double	norm(t_vect vec);
void	scalar_prod(t_vect vec, double lambda);
void	normalize(t_vect vec);

#endif /* INC_SPEC_MATH_SPEC_MATH_H_ */
