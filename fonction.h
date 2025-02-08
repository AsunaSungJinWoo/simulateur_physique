#pragma once

#include <iostream>


/*******************************/
/** DÉCLARATION DES FONCTIONS **/
/*******************************/

struct Tensions {
    double cabine;
    double contrepoids;
};

/*
{
    R : la fonction permet de calculer les tension des cable c'est a dire T_cabine et T_contrepoids
    E :le choix de de la/les tension a renvoyer (0 =tension_ cabien , 1=tension_contrepoids , 2= les deux), 
    la masse de la cabine et du contrepoids et alpha lacceleration  
    S :ils renvoie soit l'une des deux tension soit les deux en fonction du choix de l'utulisateur grace a un struct 
}
*/
Tensions Calcule_Tension(int choix_formule, 
                         int choix_donnees, 
                         float masse_cabine, 
                         float masse_contrepoids, 
                         float alpha, 
                         float moments_dinertie, 
                         float rayon, 
                         float p_moteur, 
                         float vitesse);

/*
{
    R : 
    E :
    S :
}
*/
double couple_moteur(int choix, 
                     float tension_cabine, 
                     float tension_contrepoids, 
                     float alpha, 
                     float moments_dinertie, 
                     float rayon, 
                     float puissance_moteur, 
                     float vitesse);

/*
{
    R :
    E :
    S :
}
*/
double puissance_moteur(float couple_mot, 
                        float vitesse , 
                        float rayon );


/*
{
    R :
    E :
    S :
}
*/
double rayon_poulie(float vitesse,
                    float  vitesse_angulaire);

/*
{
    R :
    E :
    S :
}
*/
double vitesse_rotation(float vitesse_angulaire);

/*
{
    R :
    E :
    S :
}
*/
double temps_montee_and_descente(float distance ,
                                 float vitesse);

/*
{
    R :
    E :
    S :
}
*/
double acceleration(int choix,
                    float masse_contrepoids, 
                    float masse_cabine,
                    float tension_contrepoids, 
                    float tension_cabine, 
                    float vitesse);

/*
{
    R :
    E :
    S :
}
*/
void test_fonction();

