#ifndef CUBOID_H
#define CUBOID_H
#include <stdbool.h>
/**
 * Data of a cuboid object in Descartes coordinate system
 */
typedef struct Cuboid
{
	double x;
	double y;
	double z;
} Cuboid;

/**
 * Set the data of the cuboid
 */
void set_size(Cuboid* cuboid, double x, double y, double z);


double calc_volume(const Cuboid* cuboid);

double calc_surface(const Cuboid* cuboid);

bool check_square(const Cuboid* cuboid);

#endif // CUBOID_H
