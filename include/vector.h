/**
 * \file vector.h
 * \brief Vector.
 * \author HABIBI Arash
 * \author RAZANAJATO RANAIVOARIVONY Harenome
 * \date September the 25th 2013 (HABIBI Arash)
 * \date 2014 (RAZANAJATO RANAIVOARIVONY Harenome)
 * \copyright WTFPL version 2
 *
 * \todo v_project_on_plane
 * \todo v_decompose
 * \todo v_recompose
 * \todo v_ux_uy_from_uz
 */
/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://www.wtfpl.net/ for more details.
 */
#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "utilities.h"

/**
 * \brief Vecteur.
 */
typedef struct
{
    float x;    /**<- x. */
    float y;    /**<- y. */
    float z;    /**<- z. */
} vector;

/**
 * \brief Point.
 */
typedef vector point;

/**
 * \brief Créer un nouveau vecteur.
 * \param x x.
 * \param y y.
 * \param z z.
 * \return Vecteur (x, y, z).
 */
vector v_new (float x, float y, float z);

/**
 * \brief Afficher un vecteur accompagné d'un message.
 * \param v Vecteur à afficher.
 * \param message Message.
 */
void v_print (vector v, const char * message);

/**
 * \brief Additionner deux vecteurs.
 * \param a Vecteur 1.
 * \param b Vecteur 2.
 * \return a + b.
 */
vector v_add (vector a, vector b);

/**
 * \brief Soustraire deux vecteurs.
 * \param a Vecteur 1.
 * \param b Vecteur 2.
 * \return a - b.
 */
vector v_substract (vector a, vector b);

/**
 * \brief Multiplier un vecteur par un scalaire.
 * \param lambda Scalaire.
 * \param v Vecteur.
 * \return Vecteur (lambda * v.x, lambda * v.y, lambda * v.z).
 */
vector v_multiply (double lambda, vector v);

/**
 * \brief Effectuer le produit vectoriel de deux vecteurs.
 * \param a Vecteur 1.
 * \param b Vecteur 2.
 * \return a ^ b.
 */
vector v_cross (vector a, vector b);

/**
 * \brief Effectuer le produit scalaire de deux vecteurs.
 * \param a Vecteur 1.
 * \param b Vecteur 2.
 * \return a . b.
 */
float v_dot (vector a, vector b);

/**
 * \brief Obtenir la norme d'un vecteur.
 * \param v Vecteur.
 * \return Norme.
 */
double v_length (vector v);

/**
 * \brief Obtenir un vecteur unitaire de même direction qu'un autre vecteur.
 * \param v Vecteur.
 * \return Vecteur unitaire.
 */
vector v_unit (vector v);

/**
 * \brief Déterminer si un point est à la droite d'une droite.
 * \param m Point M.
 * \param a Point de la droite.
 * \param b Point de la droite.
 * \retval true si \c m est à la droite de la droite (\c a, \c b).
 * \retval false sinon.
 */
bool v_is_on_the_right (point m, point a, point b);

/**
 * \brief Déterminer si deux segments s'intersectent.
 * \param a Extrémité du premier segment.
 * \param b Extrémité du premier segment.
 * \param c Extrémité du deuxième segment.
 * \param d Extrémité du deuxième segment.
 * \retval true si les deux segments s'intersectent.
 * \retval false sinon.
 */
bool v_segments_intersect (point a, point b, point c, point d);

/**
 * \brief Déterminer si une demi-droite et un segment s'intersectent.
 * \param m Origine de la demi-droite.
 * \param u_ray Vecteur directeur de la demi-droite.
 * \param a Extrémité du segment.
 * \param b Extrémité du segment.
 * \retval true si la demi-droite et le segment s'intersectent.
 * \retval false sinon.
 */
bool v_ray_intersects_segment (point m, vector u_ray, point a, point b);

/**
 * \brief Faire tourner un vecteur autour de l'axe Y.
 * \param v Vecteur à faire tourner.
 * \param angle Angle.
 * \return Vecteur.
 */
vector v_turn_around_y (vector v, double angle);

/**
 * \brief Faire tourner un vecteur autour de l'axe Z.
 * \param v Vecteur à faire tourner.
 * \param angle Angle.
 * \return Vecteur.
 */
vector v_turn_around_z (vector v, double angle);

/**
 * \brief Projeter un vecteur sur un plan.
 * \param v Vecteur à projeter.
 * \param normal Vecteur normal au plan.
 * \return Vecteur.
 */
vector v_project_on_plane (vector v, vector normal);

/**
 * \brief Obtenir la coordonnée d'un vecteur selon un autre vecteur.
 * \param p Vecteur.
 * \param u Vecteur repère.
 * \return Coordonnée selon \c u de \c p.
 */
double v_decompose (vector p, vector u);

/**
 * \brief Obtenir le vecteur de coordonnées (x,y,z) dans le repère (u,v,w).
 * \param x \c x.
 * \param y \c y.
 * \param z \c z.
 * \param u \c u.
 * \param v \c v.
 * \param w \c w.
 * \return Vecteur.
 */
vector v_recompose (double x, double y, double z, vector u, vector v, vector w);

/** \brief Obtenir \c u_x et \c u_y tels que (\c u_x, \c u_y, \c u_z) soit orthonormé direct.
 * \param[in] u_z \c u_z.
 * \param[out] u_x \c u_x.
 * \param[out] u_y \c u_y.
 */
void v_ux_uy_from_uz (vector u_z, vector * u_x, vector * u_y);

#endif // __VECTOR_H__
