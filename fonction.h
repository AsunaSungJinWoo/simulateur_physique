#pragma once

#include <iostream>
/*******************************/
/** DÉCLARATION DES FONCTIONS **/
/*******************************/

/*
{
    R : 
    E : 
    S : 
}
*/
void affichage(void );


//structure pour stocker les tensions 
struct Tensions {
    float cabine;
    float contrepoids;
};
/*
{
    R : la fonction permet de calculer les tension des cable c'est a dire T_cabine et T_contrepoids
    E :le choix de de la/les tension a renvoyer (0 =tension_ cabien , 1=tension_contrepoids , 2= les deux), 
    la masse de la cabine et du contrepoids et alpha lacceleration  
    S :ils renvoie soit l'une des deux tension soit les deux en fonction du choix de l'utulisateur grace a un struct 
}
*/
Tensions CalculeTension(int choix, float masse_cabine = 0 ,float masse_contrepoids = 0  ,float alpha = 0);

/*
{
    R : 
    E :
    S :
}
*/
float puissance_moteur(float couple_mot = 0, float vitesse = 0, float rayon = 0);

/*
{
    R :
    E :
    S :
}
*/
float rayon_poulie(float vitesse = 0, float  vitesse_angulaire = 0);



