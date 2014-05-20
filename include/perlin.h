/**
 * \file perlin.h
 * \brief Perlin.
 * \author HABIBI Arash
 * \date May the 29 2013
 */
#ifndef _PERLIN_H_
#define _PERLIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "vector.h"

#define PRLN_000 0
#define PRLN_100 1
#define PRLN_010 2
#define PRLN_110 3
#define PRLN_001 4
#define PRLN_101 5
#define PRLN_011 6
#define PRLN_111 7


//double prln_scalar_noise(vector p, double period, double amplitude, int nb_octaves, double lacunarity, double gain);
//vector prln_vector_noise(vector p, double period, double amplitude, int nb_octaves, double lacunarity, double gain);
double prln_scalar_noise (vector p);
vector prln_vector_noise (vector p);

#endif

