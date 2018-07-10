#include "draw.h"

double		dot_perlin(const int *v, const double x, const double y, \
			const double z)
{
	return (v[0] * x + v[1] * y + v[2] * z);
}

int			*get_grad(int x, int y, int z, t_perlin *p)
{
	int rand_value;

	rand_value = p->perm[z + p->perm[y + p->perm[x]]];
	return (p->grad3[rand_value & 15]);
}

double		quintic_poly(const double t)
{
	return (t * t * t * (t * (t * 6 - 15) + 10));
}

void		int_frac(double value, int *int_part, double *frac_part)
{
	*int_part = (int)value;
	if (value < 0)
		int_part -= 1;
	*frac_part = value - *int_part;
}

double		linear_interpolation(double a, double b, double t)
{
	return ((1 - t) * a + t * b);
}