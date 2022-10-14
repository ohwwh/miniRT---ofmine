#ifndef RAY_H
#define RAY_H
#include "vector.h"
#include "objects.h"

typedef struct s_ray {
	t_point origin;
	t_vec dir;
} t_ray;

typedef struct s_record {
	t_point p;
	t_vec normal;
	t_color color;
	double t_max;
	double t_min;
	double t;
	int front_face;
	int idx;
	int mat;
	double u;
	double v;
} t_record;

t_ray 	ray(t_point org, t_vec dir);
t_point 	ray_end(t_ray* ray, double t);
t_vec reflect(t_vec v, t_vec n);
int hit_sphere(t_object* s, t_ray* r, t_record* rec);
int hit_cylinder(t_object *cy, t_ray *ray, t_record *rec);
int hit_caps(t_object *cy, t_ray *ray, t_record *rec);
int hit_plane(t_object *pl, t_ray *ray, t_record* rec);
int hit_rectangle_xy(t_object *rect, t_ray *ray, t_record* rec);
int hit_rectangle_yz(t_object *rect, t_ray *ray, t_record* rec);
int hit_rectangle_xz(t_object *rect, t_ray *ray, t_record* rec);
int find_hitpoint(t_ray *ray, t_object *objs, t_record* rec);

#endif