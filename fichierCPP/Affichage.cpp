#include "Affichage.h"
#include "CalculePhysique.h"
#include "a mettre je lavait enlever car tout et mort sur csv"
#include "InterfaceGraphique.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

// Énumération pour les choix du menu
enum MenuOption {
    gi_CalculTension = 1,
    gi_CalculCouple = 2,
    gi_CalculPuissance = 3,
    gi_CalculRayon = 4,
    gi_CalculVitesseRotation = 5,
    gi_CalculTempsMontee = 6,
    gi_CalculAcceleration = 7,
    gi_UtiliserCsv = 8,
    gi_VoirSimulation = 9,
    gi_ExecuterTests = 10,
    gi_Quitter = 11,
};

// Fonction pour sécuriser l'entrée utilisateur
static void SecuriserSaisie() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Saisie invalide. Veuillez entrer une valeur correcte.\n";
    }
}

void Affichage(void) {
    // Initialisation des variables
    int li_Choix = 0;

    while (true) {
        cout << "\n==== MENU PRINCIPAL ====\n"
            << " 1. Calculer la tension\n"
            << " 2. Calculer le couple moteur\n"
            << " 3. Calculer la puissance moteur\n"
            << " 4. Calculer le rayon de la poulie\n"
            << " 5. Calculer la vitesse de rotation\n"
            << " 6. Calculer le temps de montee/descente\n"
            << " 7. Calculer l'acceleration\n"
            << " 8. Utiliser un fichier .csv\n"
            << " 9. Voir la simulation\n"
            << "10. Executer les tests\n"
            << "11. Quitter\n"
            << "Entrez votre choix : ";

        cin >> li_Choix;
        SecuriserSaisie(); // Vérifie la validité de l'entrée

        if (li_Choix < 1 || li_Choix > 11) {
            cout << "Choix invalide. Veuillez réessayer.\n";
            continue;  // Recommence le menu
        }

        switch (li_Choix) {
        case gi_CalculTension: {
            float lf_MasseCabine = 0, lf_MasseContrepoids = 0, lf_Alpha = 0;
            float lf_MomentsDinertie = 0, lf_Rayon = 0, lf_CoupleMoteur = 0, lf_Vitesse = 0;
            int li_ChoixCalcul = 0, li_ChoixTension = 0, li_ChoixResult = 0;
            Tensions result{};

            // Demander ce que l'utilisateur veut calculer
            cout << "Que voulez-vous calculer ?\n"
                << "0 = Tension cabine\n"
                << "1 = Tension contrepoids\n"
                << "2 = Les deux tensions\n"
                << "3 = Retourner en arrière\n"
                << "Votre choix : ";
            cin >> li_ChoixTension;
            SecuriserSaisie();

            if (li_ChoixTension == 3) {
                cout << "Retour au menu principal.\n";
                break;  // Retour au menu principal
            }

            switch (li_ChoixTension) {
            case CHOIX_TENSION_CABINE: {
                cout << "Choisissez la formule :\n"
                    << "0 = Utiliser accélération et masse de la cabine\n"
                    << "1 = Utiliser moments de force\n"
                    << "Votre choix : ";
                cin >> li_ChoixCalcul;
                SecuriserSaisie();

                if (li_ChoixCalcul == CHOIX_CALCUL_TENSION_AVEC_SOMME_FORCE) {
                    cout << "Entrez la masse de la cabine (kg) : "; cin >> lf_MasseCabine;
                    cout << "Entrez l'accélération angulaire (rad/s) : "; cin >> lf_Alpha;
                    SecuriserSaisie();
                }
                else if (li_ChoixCalcul == CHOIX_CALCUL_TENSION_AVEC_CM) {
                    cout << "Entrez le moment d'inertie (kg·m) : "; cin >> lf_MomentsDinertie;
                    cout << "Entrez le rayon (m) : "; cin >> lf_Rayon;
                    cout << "Entrez le couple moteur (N·m) : "; cin >> lf_CoupleMoteur;
                    cout << "Entrez la vitesse (m/s) : "; cin >> lf_Vitesse;
                    cout << "Entrez la masse du contrepoids (kg) : "; cin >> lf_MasseContrepoids;
                    cout << "Entrez l'accélération angulaire (rad/s) : "; cin >> lf_Alpha;
                    SecuriserSaisie();
                }
                else {


                }
                result = CalculerTension(li_ChoixCalcul, li_ChoixResult, lf_MasseCabine, lf_MasseContrepoids, lf_Alpha, lf_MomentsDinertie, lf_Rayon, lf_CoupleMoteur, lf_Vitesse);
                cout << "Tension cabine : " << result.cabine << " N\n";
                break;
            }
            case CHOIX_TENSION_CONTREPOIDS: {
                cout << "Choisissez la formule :\n"
                    << "0 = Utiliser accélération et masse du contrepoids\n"
                    << "1 = Utiliser moments de force\n"
                    << "Votre choix : ";
                cin >> li_ChoixCalcul;
                SecuriserSaisie();

                if (li_ChoixCalcul == CHOIX_CALCUL_TENSION_AVEC_SOMME_FORCE) {
                    cout << "Entrez la masse du contrepoids (kg) : "; cin >> lf_MasseContrepoids;
                    cout << "Entrez l'accélération angulaire (rad/s) : "; cin >> lf_Alpha;
                    SecuriserSaisie();
                }
                else if (li_ChoixCalcul == CHOIX_CALCUL_TENSION_AVEC_CM) {
                    cout << "Entrez le moment d'inertie (kg·m) : "; cin >> lf_MomentsDinertie;
                    cout << "Entrez le rayon (m) : "; cin >> lf_Rayon;
                    cout << "Entrez le couple moteur (N·m) : "; cin >> lf_CoupleMoteur;
                    cout << "Entrez la vitesse (m/s) : "; cin >> lf_Vitesse;
                    cout << "Entrez la masse de la cabine (kg) : "; cin >> lf_MasseCabine;
                    cout << "Entrez l'accélération angulaire (rad/s) : "; cin >> lf_Alpha;
                    SecuriserSaisie();
                }
                else {


                }
                result = CalculerTension(li_ChoixCalcul, li_ChoixResult, lf_MasseCabine, lf_MasseContrepoids, lf_Alpha, lf_MomentsDinertie, lf_Rayon, lf_CoupleMoteur, lf_Vitesse);
                cout << "Tension cabine : " << result.cabine << " N\n";
                break;
            }
            case CHOIX_DES_DEUX_TENSIONS: {
                li_ChoixCalcul = 0;
                cout << "Entrez la masse de la cabine (kg) : "; cin >> lf_MasseCabine;
                cout << "Entrez la masse du contrepoids (kg) : "; cin >> lf_MasseContrepoids;
                cout << "Entrez l'accélération angulaire (rad/s) : "; cin >> lf_Alpha;
                SecuriserSaisie();

                result = CalculerTension(li_ChoixCalcul, li_ChoixResult, lf_MasseCabine, lf_MasseContrepoids, lf_Alpha, lf_MomentsDinertie, lf_Rayon, lf_CoupleMoteur, lf_Vitesse);
                cout << "Tension cabine : " << result.cabine << " N\n";
                cout << "Tension contrepoids : " << result.contrepoids << " N\n";
                break;
            }

            }
            break;
        }
        case gi_CalculCouple: {
            float lf_TensionCabine = 0, lf_TensionContrepoids = 0, lf_acceleration = 0, lf_MomentsDinertie = 0, lf_Rayon = 0, lf_PMoteur = 0, lf_Vitesse = 0;
            int li_ChoixCouple;

            cout << "Choisissez (0 = couple par puissance (rayon, Pm, vitesse), 1 = couple par tensions(tension cabine/contrepoids ,moments dinertie ,acceleration)) : "; cin >> li_ChoixCouple;

            if (li_ChoixCouple == 0) {
                cout << "Entrez le rayon : "; cin >> lf_Rayon;
                cout << "Entrez la puissance moteur : "; cin >> lf_PMoteur;
                cout << "Entrez la vitesse : "; cin >> lf_Vitesse;
                SecuriserSaisie();
                cout << "Couple moteur : " << CoupleMoteur(li_ChoixCouple, lf_TensionCabine, lf_TensionContrepoids, lf_acceleration, lf_MomentsDinertie, lf_Rayon, lf_PMoteur, lf_Vitesse) << " Nm\n";
            }
            else if (li_ChoixCouple == 1) {
                cout << "Entrez l'acceleration angulaire: "; cin >> lf_acceleration;
                cout << "Entrez le moment d'inertie : "; cin >> lf_MomentsDinertie;
                cout << "Entrez la tension cabine : "; cin >> lf_TensionCabine;
                cout << "Entrez la tension contrepoids : "; cin >> lf_TensionContrepoids;
                cout << "Entrez le rayon : "; cin >> lf_Rayon;
            }
            else {
                cout << "Choix invalide, veuillez réessayer.\n";
                break;
            }
            cout << "Couple moteur : " << CoupleMoteur(li_ChoixCouple, lf_TensionCabine, lf_TensionContrepoids, lf_acceleration, lf_MomentsDinertie, lf_Rayon, lf_PMoteur, lf_Vitesse) << " Nm\n";
            break;
        }

        case gi_CalculPuissance: {
            float lf_CoupleMot, lf_Vitesse, lf_Rayon;
            cout << "Entrez le couple moteur : "; cin >> lf_CoupleMot;
            cout << "Entrez la vitesse : "; cin >> lf_Vitesse;
            cout << "Entrez le rayon : "; cin >> lf_Rayon;

            SecuriserSaisie();
            cout << "Puissance moteur : " << PuissanceMoteur(lf_CoupleMot, lf_Vitesse, lf_Rayon) << " W\n";
            break;
        }

        case gi_CalculRayon: {
            float lf_Vitesse = 0 ,lf_VitesseAngulaire = 0,lf_CoupleMot = 0,lt_PuissanceMot = 0;
            int li_ChoixCalcul;

            cout << "Choisissez la formule :\n"
                << "0 = Utiliser vitesse lineaire et vitesse angulaire\n"
                << "1 = Utiliser vitesse ,cm ,pm\n"
                << "Votre choix : ";
            cin >> li_ChoixCalcul;

            if (li_ChoixCalcul == 0) {
                cout << "Entrez la vitesse : "; cin >> lf_Vitesse;
                cout << "Entrez la vitesse angulaire : "; cin >> lf_VitesseAngulaire;
            }
            else if (li_ChoixCalcul == 1) {
                cout << "Entrez la vitesse : "; cin >> lf_Vitesse;
                cout << "Entrez le couple moteur : "; cin >> lf_CoupleMot;
                cout << "Entrez la puissance du moteur: "; cin >> lt_PuissanceMot;
            }
            else {
                cout << "Choix invalide, veuillez réessayer.\n";
                break;
            }
            SecuriserSaisie();
            cout << "Rayon de la poulie : " << RayonPoulie(li_ChoixCalcul, lf_Vitesse, lf_VitesseAngulaire, lf_CoupleMot, lt_PuissanceMot) << " m\n";
            break;
        }

        case gi_CalculVitesseRotation: {
            float lf_VitesseAngulaire;
            cout << "Entrez la vitesse angulaire : "; cin >> lf_VitesseAngulaire;

            SecuriserSaisie();
            cout << "Vitesse de rotation : " << VitesseRotation(lf_VitesseAngulaire) << " tr/min\n";
            break;
        }

        case gi_CalculTempsMontee: {
            float lf_Distance, lf_Vitesse;
            cout << "Entrez la distance : "; cin >> lf_Distance;
            cout << "Entrez la vitesse : "; cin >> lf_Vitesse;

            SecuriserSaisie();
            cout << "Temps de montee/descente : " << TempsMonteeAndDescente(lf_Distance, lf_Vitesse) << " s\n";
            break;
        }

        case gi_UtiliserCsv:
            break;

        case gi_VoirSimulation:
            SFMLSimulation();
            break;

        case gi_ExecuterTests:
            TestFonction();
            break;

        case gi_Quitter:
            cout << "Programme terminé.\n";
            return;

        default:
            cout << "Choix invalide, veuillez réessayer.\n";
        }
    }
}
