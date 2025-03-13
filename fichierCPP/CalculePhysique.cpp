#include "Affichage.h"
#include "CalculePhysique.h"

#include "InterfaceGraphique.h"

#include <cmath>
#include <cassert>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

Tensions CalculerTension(int choixFormule, int choixDonnees, float masseCabine, float masseContrepoids,
    float alpha, float momentsInertie, float rayon, float pMoteur, float vitesse) {

    float tensionCabine = 0, tensionContrepoids = 0;

    if (choixFormule == CHOIX_CALCUL_TENSION_AVEC_SOMME_FORCE) {
        tensionCabine = masseCabine * (alpha + Graviter);
        tensionContrepoids = masseContrepoids * (Graviter - alpha);
    }
    else if (choixFormule == CHOIX_CALCUL_TENSION_AVEC_CM) {
        tensionCabine = masseContrepoids * (Graviter - alpha) - (pMoteur / momentsInertie);
        tensionContrepoids = (pMoteur + (momentsInertie * masseCabine) * (alpha + Graviter)) / momentsInertie;
    }
    else {
        cout << "La valeur du choix pour la formule est invalide. Veuillez reessayer." << endl;
        return { 0, 0 };
    }

    switch (choixDonnees) {
    case CHOIX_TENSION_CABINE: return { tensionCabine, 0 };
    case CHOIX_TENSION_CONTREPOIDS: return { 0, tensionContrepoids };
    case CHOIX_DES_DEUX_TENSIONS: return { tensionCabine, tensionContrepoids };
    default:
        cout << "La valeur du choix est invalide. Veuillez reessayer." << endl;
        return { 0, 0 };
    }
}

float CoupleMoteur(int choix, float tensionCabine, float tensionContrepoids, float alpha,
                   float momentsInertie, float rayon, float pMoteur, float vitesse) {
    float cm = 0;
    switch (choix) {
    case 0:
        cm = pMoteur / (vitesse / rayon);
        break;
    case 1:
        cm = (((momentsInertie * alpha) / rayon) - rayon * (tensionContrepoids - tensionCabine));
        break;
    default:
        cout << "La valeur du choix est invalide. Veuillez reessayer." << endl;
        return 0;
    }
    if (cm < 0) {
        return cm * -1;
    }
    else {
        return cm;
    }
}

float PuissanceMoteur(float coupleMot, float vitesse, float rayon) {
    if (rayon == 0) {
        cerr << "Erreur : division par zéro dans PuissanceMoteur !" << endl;
        return 0;
    }
    return coupleMot * (vitesse / rayon);
}

float RayonPoulie(int choix ,float vitesse ,float vitesseAngulaire ,float CoupleMoteur ,float PuissanceMoteur) {
    if (choix == 0){
        return vitesse / vitesseAngulaire;
    }
    else if (choix == 1) {
        return (vitesse * CoupleMoteur) / PuissanceMoteur;
    }
}

float VitesseRotation(float vitesseAngulaire) {
    return (vitesseAngulaire * 30) / M_PI;
}

float TempsMonteeAndDescente(float distance, float vitesse) {
    return distance / vitesse;
}

float Acceleration(int choix, float masseContrepoids, float masseCabine, float tensionContrepoids, float tensionCabine, float vitesse) {
    if (choix == 0) {
        return (tensionCabine - masseCabine * Graviter) / masseCabine;
    }
    else if (choix == 1) {
        return (tensionContrepoids - masseContrepoids * Graviter) / masseContrepoids;
    }
    else if (choix == 2) {
        return 0; // A faire voir si on le fait vraiment
    }
    else {
        cout << "La valeur du choix est invalide. Veuillez reessayer.";
        return 0;
    }
}

void TestFonction() {
    try {
        Tensions t1 = CalculerTension(0, 0, 350, 100, 0.3, 0, 0, 0, 0);
        assert(fabs(t1.cabine - 3538.5) < 0.01 && "Erreur: CalculerTension test 1");

        float couple = CoupleMoteur(0, 0,0,0,0,0.3,3750,1.5);
        assert(fabs(couple - 750) < 0.1 && "Erreur: CoupleMoteur test 1");
        couple = CoupleMoteur(1, 3538.5, 951, 0.1, 0.1, 0.3, 0, 0);
        assert(fabs(couple - 776.2833) < 0.1 && "Erreur: CoupleMoteur test 2");

        assert(fabs(PuissanceMoteur(750, 1.5, 0.3) - 3750) < 0.01 && "Erreur: PuissanceMoteur test 1");

        assert(fabs(RayonPoulie(0,1.5,3,0,0) - 0.5) < 0.01 && "Erreur: RayonPoulie test 1");
        assert(fabs(RayonPoulie(1, 1.5, 0, 750, 3750) - 0.3) < 0.01 && "Erreur: RayonPoulie test 1");

        assert(fabs(VitesseRotation(10.0) - 95.49) < 0.01 && "Erreur: VitesseRotation test 1");

        assert(fabs(TempsMonteeAndDescente(20.0, 2.0) - 10.0) < 0.01 && "Erreur: TempsMonteeAndDescente test 1");

        assert(fabs(Acceleration(0, 100, 350, 951, 3538.5, 2.0) - 0.3) < 0.01 && "Erreur: Acceleration test 1");

        cout << "Tous les tests sont reussis !" << endl;
    }
    catch (const exception& e) {
        cerr << "Erreur lors de l'exécution des tests ! Détails : " << e.what() << endl;
    }
}
