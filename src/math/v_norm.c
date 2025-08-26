/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_vect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:32:36 by okientzl          #+#    #+#             */
/*   Updated: 2025/08/26 14:02:31 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/mini_rt.h"

/*
 * NORMALISATION D'UN VECTEUR
 * 
 * QU'EST-CE QUE LA NORMALISATION ?
 * ================================
 * Imaginer un vecteur comme une flèche dans l'espace :
 * - La flèche a une DIRECTION (où elle pointe)
 * - La flèche a une LONGUEUR (sa magnitude)
 * 
 * Normaliser = garder la MÊME direction mais changer la longueur à exactement 1.0
 * 
 * POURQUOI C'EST UTILE ?
 * ======================
 * - Les calculs d'éclairage ont besoin de vecteurs de longueur 1
 * - Les directions de rayons doivent être normalisées
 * - Plus facile de comparer des directions sans se soucier des longueurs
 * 
 * EXEMPLE CONCRET :
 * =================
 * Vecteur original : (3, 4, 0) → longueur = 5
 * Vecteur normalisé : (0.6, 0.8, 0) → longueur = 1, même direction
 * 
 * MÉTHODE :
 * =========
 * Pour normaliser : diviser chaque composante par la longueur totale
 * normalized = original / ||original||
 */
t_vec3	v_norm(t_vec3 a)
{
    double length;
    
    // Étape 1 : Calculer la longueur du vecteur
    // ||a|| = sqrt(x² + y² + z²)
    length = v_len(a);
    
    // Étape 2 : Vérifier si le vecteur n'est pas nul
    // PROBLÈME : si length = 0, division par zéro = crash !
    // CAS PROBLÉMATIQUE : vecteur (0, 0, 0) → impossible à normaliser
    if (length > 0.0)
    {
        // CAS NORMAL : diviser chaque composante par la longueur
        // Résultat : vecteur de même direction, longueur = 1
        return v_scale(a, 1.0 / length);
    }
    else
    {
        // CAS D'ERREUR : vecteur nul, on retourne le vecteur original
        // (Ou on pourrait retourner un vecteur par défaut comme (1,0,0))
        return a;
    }
}
