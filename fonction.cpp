#include <iostream>
#include "fonction.h"
#include <cassert>
#include <cmath>

# define M_PI           3.14159265358979323846  /* pi */
# define g              9.81   //la graviter




using namespace std;


void Affichage(void)
{
    // initialisation des variables
    int choix;

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
            Tensions result = Calcule_Tension(choix_tension, choix_result, masse_cabine, masse_contrepoids, alpha, moments_dinertie, rayon, p_moteur, vitesse);
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
}


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
