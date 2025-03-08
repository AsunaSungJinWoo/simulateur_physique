#pragma once

#include <iostream>


struct Tensions {
    double cabine;
    double contrepoids;
};



/*
{
    R :Sert à afficher les différents choix que peut faire l'utilisateur au début du programme
}
*/
void Affichage(void);





void Affichage_donnee(void);
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
    R : La fonction permet de calculer le couple
    E : prend en entrée: le choix de la formule, la tension de la cabine/contrepoids, la vitesse angulaire,
        le moment d'inertie,le rayon de la poulie, la puissance du moteur et sa vitesse
    S : La fonction renvoie la valeur du couple moteur
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
    R :La fonction permet de calculer la puissance du moteur
    E : Prend en entrée: la valeur du couple moteur, la vitesse, et le rayon de la poulie
    S : La fonction renvoie la valeur de la puissance moteur
}
*/
double puissance_moteur(float couple_mot,
    float vitesse,
    float rayon);


/*
{
    R :La fonction permet de calculer le rayon de la poulie
    E :Prend en entrée: la vitesse et la vitesse angulaire de l'ascenseur
    S :La fonction renvoie la valeur du rayon de la poulie
}
*/
double rayon_poulie(float vitesse,
    float  vitesse_angulaire);

/*
{
    R :La fonction permet de calculer la vitesse de rotation
    E :Prend en entrée la vitesse angulaire
    S :La fonction renvoie la valeur de la vitesse de rotation
}
*/
double vitesse_rotation(float vitesse_angulaire);

/*
{
    R :La fonction permet de calculer le temps de montée et de descente
    E :Prend en entrée la distance ainsi que la vitesse de l'ascenseur
    S :La fonction renvoie la valeur du temps de montée et de descente
}
*/
double temps_montee_and_descente(float distance,
    float vitesse);

/*
{
    R :La fonction permet de calculer l'accélération
    E :Prend en entrée: le choix de la formule, la masse de la cabine et du contrepoids, la vitesse, la tension de la cabine et du coontrepoids
    S :La fonction renvoie la valeur de l'accelération
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
    R :La fonction permet de tester si les calculs des fonctions sont corrects
    S :La fonction renvoie le résultat des test sur les fonctions
}
*/
void test_fonction();

/*
{
    R :
    S :
}
*/
void sfml_simu(void);
