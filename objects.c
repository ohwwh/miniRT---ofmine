#include "objects.h"


int front_face(t_ray *r, t_record* rec)
{
	if (vdot(r->dir, rec->normal) > 0.0)
	{
		rec->normal = vec_scalar_mul(rec->normal, -1);
		return (0);
	}
	return (1);
}

int hit_sphere(t_object* s, t_ray* r, t_record* rec)
{
	t_vec oc = create_vec(r->origin.x - s->center.x
	,r->origin.y - s->center.y
	,r->origin.z - s->center.z);
	double sqrtd;
	double root;
	double a = vdot((r->dir), (r->dir));
	double b = vdot(oc, (r->dir));
	double c = vdot(oc, oc) - s->radius * s->radius;
	double discriminant = b * b - a * c;
	if (discriminant < 0)
			return (0);
	sqrtd = sqrt(discriminant);
	root = (-b - sqrtd) / a;
	if (root < rec->t_min || rec->t_max < root)
	{
		root = (-b + sqrtd) / a;
		if (root < rec->t_min || rec->t_max < root)
			return (0);
	}
	rec->t = root;
	rec->p = ray_end(r, root);
	rec->t_max = root;
	rec->normal = vec_division(vec_sub(rec->p, s->center), s->radius);
	rec->color = s->color;
	rec->mat = s->mat;
	front_face(r, rec);
	return (1);
}

t_object create_sphere(t_point c, double r, t_color color, int mat)
{
	t_object ret;

    ret.type = 3;
	ret.center = c;
	ret.radius = r;
	ret.color = color;
	ret.mat = mat;
	return (ret);
}