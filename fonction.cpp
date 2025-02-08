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




Tensions Calcule_Tension(int choix_formule,
                         int choix_donnees,
                         float masse_cabine,
                         float masse_contrepoids,
                         float alpha,
                         float moments_dinertie,
                         float rayon,
                         float p_moteur,
                         float vitesse)
{
    //inisialisation
    int choix2 = 0;

    //calcul des tension
    double tension_cabine , tension_contrepoids;

    //programme de la fonction
    if (choix_formule == 0)
    {
        tension_cabine = masse_cabine * (alpha + g);
        tension_contrepoids = masse_contrepoids * (g - alpha);

        if (choix_donnees == 0)
        {
            return Tensions{ tension_cabine,0 };
        }
        else if (choix_donnees == 1)
        {
            return Tensions{ 0,tension_contrepoids };
        }
        else if (choix_donnees == 2)
        {
            return Tensions{ tension_cabine,tension_contrepoids };
        }
        else
        {
            cout << "La valeur du choix est invalide. Veuillez réessayer.";
            return { 0 , 0 };
        }
    }
    if (choix_formule == 1)
    {
        tension_cabine = masse_contrepoids * (g - alpha) - (p_moteur/moments_dinertie) ;
        tension_contrepoids = (p_moteur + (moments_dinertie * masse_cabine) * (alpha + g)) / moments_dinertie;

        if (choix_donnees == 0)
        {
            return Tensions{ tension_cabine,0 };
        }
        else if (choix_donnees == 1)
        {
            return Tensions{ 0,tension_contrepoids };
        }
        else if (choix_donnees == 2)
        {
            return Tensions{tension_cabine,tension_contrepoids };
        }
        else
        {
            cout << "La valeur du choix est invalide. Veuillez réessayer.";
            return Tensions{ 0 , 0 };
        }
    }
    else
    {
        cout << "La valeur du choix pour la formule a utuliser est invalide. Veuillez réessayer.";
        return { 0 , 0 };
    }
    
}


double couple_moteur(int choix, 
                     float tension_cabine, 
                     float tension_contrepoids, 
                     float alpha, 
                     float moments_dinertie, 
                     float rayon, 
                     float p_moteur, 
                     float vitesse)
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


double puissance_moteur(float couple_mot,
                        float vitesse, 
                        float rayon)
{
    return couple_mot * (vitesse / rayon);
}


double rayon_poulie(float vitesse, 
                    float  vitesse_angulaire)
{
    return vitesse / vitesse_angulaire;
}


double vitesse_rotation(float vitesse_angulaire)
{
    return (vitesse_angulaire * 30) / M_PI;
}


double temps_montee_and_descente(float distance,
                                 float vitesse)
{
    return distance / vitesse;
}


double acceleration(int choix,
                    float masse_contrepoids, 
                    float masse_cabine, 
                    float tension_contrepoids, 
                    float tension_cabine, 
                    float vitesse)
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
        Tensions t1 = Calcule_Tension(0,0, 350, 100, 0.3,0,0,0,0);
        assert(fabs(t1.cabine - 3538.5) < 0.01);

        double couple = couple_moteur(1, 3538.5, 951, 0.1, 0.1, 0.3, 2000, 2.0);
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
