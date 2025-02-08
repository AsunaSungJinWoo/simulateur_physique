#include "fonction.h"
#include <iostream>
#include <cassert>

using namespace std;

/* IDEE GENERALE DU PROGRAMME */
/*
 * le programme nous permet d'obtenir toute les donnes relatif d'un ascenseur tel que le couple moteur ,la puissance du moteur ,les tension ect...
 * ce programme est constituer de formule de physique ou chaque valeur a calculer sera dans des fonction.
 */


/*************************/
/** PROGRAMME PRINCIPAL **/
/*************************/


int main()
{
    // initialisation des variables
    int choix;

    //Programme 
    while (true) { // Boucle pour répéter le menu
        cout << "\n=== MENU PRINCIPAL ===\n";
        cout << "1. Calculer la tension\n";
        cout << "2. Calculer le couple moteur\n";
        cout << "3. Calculer la puissance moteur\n";
        cout << "4. Calculer le rayon de la poulie\n";
        cout << "5. Calculer la vitesse de rotation\n";
        cout << "6. Calculer le temps de montee/descente\n";
        cout << "7. Calculer l'acceleration\n";
        cout << "8. Executer les tests\n";
        cout << "9. Quitter\n";
        cout << "Entrez votre choix : ";
        cin >> choix;

        if (choix == 9) {
            cout << "Programme termine.\n";
            break;
        }

        switch (choix) {
        case 1: {
            float masse_cabine, 
                  masse_contrepoids, 
                  alpha, 
                  moments_dinertie, 
                  rayon, 
                  p_moteur, 
                  vitesse;

            int choix_tension, 
                choix_result;

            cout << "Entrez la masse de la cabine : "; cin >> masse_cabine;
            cout << "Entrez la masse du contrepoids : "; cin >> masse_contrepoids;
            cout << "Entrez l acceleration alpha : "; cin >> alpha;
            cout << "Entrez le moment d'inertie : "; cin >> moments_dinertie;
            cout << "Entrez le rayon : "; cin >> rayon;
            cout << "Entrez la puissance moteur : "; cin >> p_moteur;
            cout << "Entrez la vitesse : "; cin >> vitesse;
            cout << "donner la formule a utuliser en fonction des valeur que vous avez (0 = acceleration et masse , 1 = les moments de force, les moments dinertie et acceleration";
            cin >> choix_tension;
            cout << "donner le resulta de sortie (0 = tension cabien 1 = tension contrepoids, 2 = les deux";cin >> choix_result;
            Tensions result = Calcule_Tension(choix_tension,choix_result , masse_cabine, masse_contrepoids, alpha, moments_dinertie, rayon, p_moteur, vitesse );
            cout << "Tension cabine: " << result.cabine << " N, Tension contrepoids: " << result.contrepoids << " N\n";
            break;
        }
        case 2: {
            float tension_cabine, 
                  tension_contrepoids, 
                  alpha, 
                  moments_dinertie, 
                  rayon, 
                  p_moteur, 
                  vitesse;

            int choix_couple;

            cout << "Entrez la tension cabine : "; cin >> tension_cabine;
            cout << "Entrez la tension contrepoids : "; cin >> tension_contrepoids;
            cout << "Entrez l'accélération alpha : "; cin >> alpha;
            cout << "Entrez le moment d'inertie : "; cin >> moments_dinertie;
            cout << "Entrez le rayon : "; cin >> rayon;
            cout << "Entrez la puissance moteur : "; cin >> p_moteur;
            cout << "Entrez la vitesse : "; cin >> vitesse;
            cout << "Choisissez (0 = couple moteur par puissance, 1 = couple moteur par tensions) : ";
            cin >> choix_couple;
            cout << "Couple moteur : " << couple_moteur(choix_couple, tension_cabine, tension_contrepoids, alpha, moments_dinertie, rayon, p_moteur, vitesse) << " Nm\n";
            break;
        }
        case 3: {
            float couple_mot, 
                  vitesse, 
                  rayon;

            cout << "Entrez le couple moteur : "; cin >> couple_mot;
            cout << "Entrez la vitesse : "; cin >> vitesse;
            cout << "Entrez le rayon : "; cin >> rayon;
            cout << "Puissance moteur : " << puissance_moteur(couple_mot, vitesse, rayon) << " W\n";
            break;
        }
        case 4: {
            float vitesse, 
                  vitesse_angulaire;

            cout << "Entrez la vitesse : "; cin >> vitesse;
            cout << "Entrez la vitesse angulaire : "; cin >> vitesse_angulaire;
            cout << "Rayon de la poulie : " << rayon_poulie(vitesse, vitesse_angulaire) << " m\n";
            break;
        }
        case 5: {
            float vitesse_angulaire;

            cout << "Entrez la vitesse angulaire : "; cin >> vitesse_angulaire;
            cout << "Vitesse de rotation : " << vitesse_rotation(vitesse_angulaire) << " tr/min\n";
            break;
        }
        case 6: {
            float distance, 
                  vitesse;

            cout << "Entrez la distance : "; cin >> distance;
            cout << "Entrez la vitesse : "; cin >> vitesse;
            cout << "Temps de montée/descente : " << temps_montee_and_descente(distance, vitesse) << " s\n";
            break;
        }
        case 7: {
            float masse_cabine, 
                  masse_contrepoids,
                  tension_cabine,
                  tension_contrepoids,
                  vitesse;

            int choix_acc;

            cout << "Entrez la masse de la cabine : "; cin >> masse_cabine;
            cout << "Entrez la masse du contrepoids : "; cin >> masse_contrepoids;
            cout << "Entrez la tension cabine : "; cin >> tension_cabine;
            cout << "Entrez la tension contrepoids : "; cin >> tension_contrepoids;
            cout << "Entrez la vitesse : "; cin >> vitesse;
            cout << "Choisissez (0 = cabine, 1 = contrepoids, 2 = aucun) : ";
            cin >> choix_acc;
            cout << "Accélération : " << acceleration(choix_acc, masse_contrepoids, masse_cabine, tension_contrepoids, tension_cabine, vitesse) << " m/s²\n";
            break;
        }
        case 8:
            test_fonction();
            break;
        default:
            cout << "Choix invalide, veuillez réessayer.\n";
        }
    }

    return 0;
}
