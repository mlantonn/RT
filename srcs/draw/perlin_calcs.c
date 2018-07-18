#include "draw.h"

double	LERP(double t, double a, double b)
{
	return (1 - t) * a + t * b;
}

double	curve(const double t)
{
	return (t * t * t * (t * (t * 6 - 15) + 8));
}

double	AT3(const float *v, const double x, const double y, \
			const double z)
{
		return (v[0] * x + v[1] * y + v[2] * z);
}