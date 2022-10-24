#ifndef VECTOR_H
#define VECTOR_H
#include "math.h"
#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415926535897932385
#define EPS 0.01
#define WIDTH 640
#define HEIGHT 320

typedef struct s_vec {
	double x;
	double y;
	double z;
} t_vec;

typedef t_vec t_point;
typedef t_vec t_color;

t_vec	create_vec(double x, double y, double z);
void	set_vec(t_vec *vec, double x, double y, double z);
double	vec_len(t_vec vec);
t_vec	vec_sum(t_vec vec1, t_vec vec2);
t_vec	vec_sub(t_vec vec, t_vec vec2);
t_vec 	vec_scalar_mul(t_vec vec, double s);
t_vec   vec_mul(t_vec vec1, t_vec vec2);
t_vec	vec_division(t_vec vec, double t);
double	vdot(t_vec vec, t_vec vec2);
t_vec	vcross(t_vec vec1, t_vec vec2);
t_vec   unit_vec(t_vec vec);
t_vec	vmin(t_vec vec1, t_vec vec2);

#endif