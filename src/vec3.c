#include "../include/mini_rt.h"

t_vec3 vec_add(t_vec3 a, t_vec3 b)
{
	t_vec3 r;
	r.x = a.x + b.x;
	r.y = a.y + b.y;
	r.z = a.z + b.z;
	return (r);
}

t_vec3 vec_sub(t_vec3 a, t_vec3 b)
{
	t_vec3 r;
	r.x = a.x - b.x;
	r.y = a.y - b.y;
	r.z = a.z - b.z;
	return (r);
}

t_vec3 vec_scale(t_vec3 v, double s)
{
	t_vec3 r;

	r.x = v.x * s;
	r.y = v.y * s;
	r.z = v.z * s;
	return (r);
}

double vec_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec3 vec_cross(t_vec3 a, t_vec3 b)
{
	t_vec3 r;
	r.x = a.y * b.z - a.z * b.y;
	r.y = a.z * b.x - a.x * b.z;
	r.z = a.x * b.y - a.y * b.x;
	return (r);
}

double vec_length(t_vec3 v)
{
	return (sqrt(vec_dot(v, v)));
}

t_vec3 vec_normalize(t_vec3 v)
{
	double len;
	t_vec3 r;

	len = vec_length(v);
	if (len == 0.0)
		return (v);
	r.x = v.x / len;
	r.y = v.y / len;
	r.z = v.z / len;
	return (r);
}
