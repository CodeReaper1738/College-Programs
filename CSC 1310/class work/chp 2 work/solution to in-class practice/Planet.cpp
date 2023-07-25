#include "Planet.h"

//ACCESSOR FUNCTIONS
double Planet::getMinSurfaceTemp() const
{
	return this->minSurfaceTemp;
}
double Planet::getMaxSurfaceTemp() const
{
	return this->maxSurfaceTemp;
}
double Planet::getRadius() const
{
	return this->radius;
}

//MUTATOR FUNCTIONS
void Planet::setMinSurfaceTemp(double min)
{
	this->minSurfaceTemp = min;
}
void Planet::setMaxSurfaceTemp(double max)
{
	this->maxSurfaceTemp = max;
}
void Planet::setRadius(double r)
{
	this->radius = r;
}