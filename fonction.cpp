#include <iostream>
#include "fonction.h"
#include <cassert>
#include <cmath>

# define M_PI           3.14159265358979323846  /* pi */
# define g              9.81   //la graviter

using namespace std;


/******************************/
/** DÉFINITION DES FONCTIONS **/
/******************************/




Tensions CalculeTension(int choix, float masse_cabine , float masse_contrepoids , float alpha )
{
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
float couple_moteur(int choix, float tension_cabine , float tension_contrepoids , float alpha , float moments_dinertie , float rayon , float p_moteur , float vitesse)
{
    if (choix == 0)
    {
        return (p_moteur * rayon) / vitesse;
    }
    else if (choix == 1)
    {
        return ((moments_dinertie * alpha) / rayon) * (tension_contrepoids - tension_cabine) * rayon;
    }
    else
    {
        cout << "La valeur du choix est invalide. Veuillez réessayer.";
        return 0;
    }
}


float puissance_moteur(float couple_mot , float vitesse , float rayon)
{
    return couple_mot * (vitesse / rayon);
}


float rayon_poulie(float vitesse , float  vitesse_angulaire)
{
    return vitesse / vitesse_angulaire;
}


float vitesse_rotation(float vitesse_angulaire)
{
    return (vitesse_angulaire * 30) / M_PI;
}

float temps_montee_and_descente(float distance , float vitesse )
{
    return distance / vitesse;
}

float acceleration(int choix , float masse_contrepoids , float masse_cabine , float tension_contrepoids , float tension_cabine , float vitesse )
{
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

void test_fonction()
{
    try
    {
        Tensions t1 = CalculeTension(0, 350, 100, 0.3);
        assert(fabs(t1.cabine - 3538.5) < 0.01);

        float couple = couple_moteur(1, 3538.5, 951, 0.1, 0.1, 0.3, 2000, 2.0);
        assert(fabs(couple - 749.4) > 0.01);

        assert(fabs(puissance_moteur(749.4, 2.0, 0.3) - 4996) < 0.01);
        assert(fabs(rayon_poulie(2.0, 10.0) - 0.2) < 0.01);
        assert(fabs(vitesse_rotation(10.0) - 95.49) < 0.01);
        assert(fabs(temps_montee_and_descente(20.0, 2.0) - 10.0) < 0.01);
        assert(fabs(acceleration(0, 100, 350, 951, 3538.5, 2.0) - 0.3) < 0.01);

         
        cout << " Tous les tests sont reussis !" << endl;
        
    }
    catch (...)
    {
        cerr << " Erreur lors de l'exécution des tests !" << endl;
    }
}
