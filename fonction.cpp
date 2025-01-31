#include <iostream>
#include "fonction.h"
#define _USE_MATH_DEFINES

using namespace std;


/******************************/
/** DÉFINITION DES FONCTIONS **/
/******************************/

void affichage(void);




Tensions CalculeTension(int choix, float masse_cabine = 0, float masse_contrepoids = 0, float alpha = 0)
{
    //initialisation des variables
    const float g = 9.81; //constante de gravité

    //calcul des tension
    float tension_cabine = masse_cabine * (alpha + g);
    float tension_contrepoids = masse_contrepoids * (g - alpha);

    //programme de la fonction
    if (choix == 0)
    {
        return { tension_cabine,0 };
    }
    else if (choix == 1)
    {
        return { 0,tension_contrepoids };
    }
    else if (choix == 2)
    {
        return{ tension_cabine,tension_contrepoids };
    }
    else
    {
        cout << "La valeur du choix est invalide. Veuillez réessayer.";
        return { 0 , 0 };
    }
}
float couple_moteur(int choix, float tension_cabine = 0, float tension_contrepoids = 0, float alpha = 0, float moments_dinertie = 0, float rayon = 0, float puissance_moteur = 0, float vitesse = 0)
{
    //initialisation des variables

    const float g = 9.81; //constante de gravité

    //calcul du couple moteur

    if (choix == 0)
    {
        return (puissance_moteur * rayon) / vitesse;
    }
    else if (choix == 1)
    {
        return ((moments_dinertie * alpha) / rayon) + (tension_contrepoids - tension_cabine) * rayon;
    }
    else
    {
        cout << "La valeur du choix est invalide. Veuillez réessayer.";
        return 0;
    }
}


float puissance_moteur(float couple_mot = 0, float vitesse = 0, float rayon = 1)
{
    //initialisation des variables

    const float g = 9.81; //constante de gravité

    //calcul de la puissance du moteur

    return couple_mot * (vitesse / rayon);
}


float rayon_poulie(float vitesse = 0, float  vitesse_angulaire = 1)
{
    return vitesse / vitesse_angulaire;
}


float vitesse_rotation(float vitesse_angulaire = 1)
{
    return (vitesse_angulaire * 30) / M_PI;
}

float temps_montee_and_descente(float distance = 1, float vitesse = 0)
{
    return distance / vitesse;
}

float acceleration(int choix = 0, float masse_contrepoids = 0, float masse_cabine = 0, float tension_contrepoids = 0, float tension_cabine = 0, float vitesse = 0)
{
    //initialisation des variables
    const float g = 9.81; //constante de gravité
    float acceleration = 0;

    //programme de la fonction
    if (choix == 0)
    {

        return (tension_cabine - masse_cabine * g) / masse_cabine;
    }
    else if (choix == 1)
    {
        return (tension_contrepoids - masse_contrepoids * g) / masse_contrepoids;
    }
    else if (choix == 2)
    {
        return 0;// a faire voir si on le fait vraiment
    }
    else
    {
        cout << "La valeur du choix est invalide. Veuillez réessayer.";
        return 0 ;
    }
}

