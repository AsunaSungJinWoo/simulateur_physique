#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "fonction.h"
#include <cassert>
#include <cmath>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <filesystem> 

// On définit nos constantes
#define M_PI 3.14159265358979323846  // pi
#define g 9.81  // constante de gravité

// On définit les différents choix qui pourront être effectués lors des calculs
#define choix_calcul_tension_avec_somme_force 0
#define choix_calcul_tension_avec_cm 1
#define choix_tension_cabine 0
#define choix_tension_contrepoids 1
#define choix_des_deux_tension 2

using namespace std;



void Affichage(void) {
    // Initialisation des variables
    int choix;

    while (true) { // Boucle pour répéter le menu après chaque calcul/choix
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
        cout << "10. Utiliser un fichier .csv\n";
        cout << "11. voir la simulation\n";
        cout << "Entrez votre choix : ";
        cin >> choix;

        if (choix == 10) {
            Affichage_donnee();
        }

        // Choix pour quitter le programme
        if (choix == 9) {
            cout << "Programme termine.\n";
            break;
        }

        // Choix 1 : Calculer la tension
        switch (choix) {
        case 1: {
            float masse_cabine, masse_contrepoids, alpha, moments_dinertie, rayon, p_moteur, vitesse;
            int choix_tension, choix_result;

            cout << "Entrez la masse de la cabine : "; cin >> masse_cabine;
            cout << "Entrez la masse du contrepoids : "; cin >> masse_contrepoids;
            cout << "Entrez l'acceleration angulaire : "; cin >> alpha;
            cout << "Entrez le moment d'inertie : "; cin >> moments_dinertie;
            cout << "Entrez le rayon : "; cin >> rayon;
            cout << "Entrez la puissance moteur : "; cin >> p_moteur;
            cout << "Entrez la vitesse : "; cin >> vitesse;
            cout << "Donner la formule a utiliser en fonction des valeurs que vous avez (0 = acceleration et masse, 1 = les moments de force, les moments d'inertie et acceleration) : ";
            cin >> choix_tension;
            cout << "Donner le resultat de sortie (0 = tension cabine, 1 = tension contrepoids, 2 = les deux) : ";
            cin >> choix_result;

            Tensions result = Calcule_Tension(choix_tension, choix_result, masse_cabine, masse_contrepoids, alpha, moments_dinertie, rayon, p_moteur, vitesse);
            cout << "Tension cabine: " << result.cabine << " N, Tension contrepoids: " << result.contrepoids << " N\n";
            break;
        }

              // Choix 2 : Calculer le couple moteur
        case 2: {
            float tension_cabine, tension_contrepoids, alpha, moments_dinertie, rayon, p_moteur, vitesse;
            int choix_couple;

            cout << "Entrez la tension cabine : "; cin >> tension_cabine;
            cout << "Entrez la tension contrepoids : "; cin >> tension_contrepoids;
            cout << "Entrez l'acceleration angulaire: "; cin >> alpha;
            cout << "Entrez le moment d'inertie : "; cin >> moments_dinertie;
            cout << "Entrez le rayon : "; cin >> rayon;
            cout << "Entrez la puissance moteur : "; cin >> p_moteur;
            cout << "Entrez la vitesse : "; cin >> vitesse;
            cout << "Choisissez (0 = couple moteur par puissance, 1 = couple moteur par tensions) : ";
            cin >> choix_couple;
            cout << "Couple moteur : " << couple_moteur(choix_couple, tension_cabine, tension_contrepoids, alpha, moments_dinertie, rayon, p_moteur, vitesse) << " Nm\n";
            break;
        }

              // Choix 3 : Calculer la puissance moteur
        case 3: {
            float couple_mot, vitesse, rayon;

            cout << "Entrez le couple moteur : "; cin >> couple_mot;
            cout << "Entrez la vitesse : "; cin >> vitesse;
            cout << "Entrez le rayon : "; cin >> rayon;
            cout << "Puissance moteur : " << puissance_moteur(couple_mot, vitesse, rayon) << " W\n";
            break;
        }

              // Choix 4 : Calculer le rayon de la poulie
        case 4: {
            float vitesse, vitesse_angulaire;

            cout << "Entrez la vitesse : "; cin >> vitesse;
            cout << "Entrez la vitesse angulaire : "; cin >> vitesse_angulaire;
            cout << "Rayon de la poulie : " << rayon_poulie(vitesse, vitesse_angulaire) << " m\n";
            break;
        }

              // Choix 5 : Calculer la vitesse angulaire
        case 5: {
            float vitesse_angulaire;

            cout << "Entrez la vitesse angulaire : "; cin >> vitesse_angulaire;
            cout << "Vitesse de rotation : " << vitesse_rotation(vitesse_angulaire) << " tr/min\n";
            break;
        }

              // Choix 6 : Calculer le temps de montee et de descente
        case 6: {
            float distance, vitesse;

            cout << "Entrez la distance : "; cin >> distance;
            cout << "Entrez la vitesse : "; cin >> vitesse;
            cout << "Temps de montee/descente : " << temps_montee_and_descente(distance, vitesse) << " s\n";
            break;
        }

              // Choix 7 : Calculer l'acceleration
        case 7: {
            float masse_cabine, masse_contrepoids, tension_cabine, tension_contrepoids, vitesse;
            int choix_acc;

            cout << "Entrez la masse de la cabine : "; cin >> masse_cabine;
            cout << "Entrez la masse du contrepoids : "; cin >> masse_contrepoids;
            cout << "Entrez la tension cabine : "; cin >> tension_cabine;
            cout << "Entrez la tension contrepoids : "; cin >> tension_contrepoids;
            cout << "Entrez la vitesse : "; cin >> vitesse;
            cout << "Choisissez (0 = cabine, 1 = contrepoids, 2 = aucun) : ";
            cin >> choix_acc;
            cout << "Acceleration : " << acceleration(choix_acc, masse_contrepoids, masse_cabine, tension_contrepoids, tension_cabine, vitesse) << " m/s²\n";
            break;
        }

              // Choix 8 : Executer les tests
        case 8: {
            test_fonction();
            break;
        }
        case 11: {
            sfml_simu();
            break;
        }
               // Choix invalide
        default:
            cout << "Choix invalide, veuillez reessayer.\n";
        }
    }
}

void Affichage_donnee(void) {
    // Initialisation des variables
    double m_cabine = 0.0, m_contrepoids = 0.0, t_cabine = 0.0, t_contrepoids = 0.0, r_poulie = 0.0, vitesse_max = 0.0, duree_acceleration = 0.0, couple_mot = 0.0, puissance_mot = 0.0, a_angulaire = 0.0, mom_inertie = 0.0, distance = 0.0;
    int choix_donne = 0;
    string ligne;
    ifstream le_fichier; // Flux de fichier d'entrée

    // Algorithme
    le_fichier.open("../dependances_exterieurs/Fichier_Donnee.csv", ios::in); // Ouverture du fichier en lecture
    if (le_fichier.is_open()) {
        // Lire et ignorer la première ligne (en-tête)
        getline(le_fichier, ligne);

        // Lire la deuxième ligne
        getline(le_fichier, ligne);

        le_fichier.close();

        // Convertir la ligne en tableau de caractères
        std::vector<char> str(ligne.begin(), ligne.end());
        str.push_back('\0'); // Ajouter un caractère nul à la fin

        // Décomposer la ligne en tokens
        char* pch = strtok(str.data(), " ;");
        if (pch != nullptr) {
            m_cabine = atof(pch);
            pch = strtok(nullptr, " ;");
        }
        if (pch != nullptr) {
            m_contrepoids = atof(pch);
            pch = strtok(nullptr, " ;");
        }
        if (pch != nullptr) {
            r_poulie = atof(pch);
            pch = strtok(nullptr, " ;");
        }
        if (pch != nullptr) {
            vitesse_max = atof(pch);
            pch = strtok(nullptr, " ;");
        }
        if (pch != nullptr) {
            duree_acceleration = atof(pch);
            pch = strtok(nullptr, " ;");
        }
        if (pch != nullptr) {
            couple_mot = atof(pch);
            pch = strtok(nullptr, " ;");
        }
        if (pch != nullptr) {
            puissance_mot = atof(pch);
            pch = strtok(nullptr, " ;");
        }
        if (pch != nullptr) {
            t_cabine = atof(pch);
            pch = strtok(nullptr, " ;");
        }
        if (pch != nullptr) {
            t_contrepoids = atof(pch);
            pch = strtok(nullptr, " ;");
        }
        if (pch != nullptr) {
            a_angulaire = atof(pch);
            pch = strtok(nullptr, " ;");
        }
        if (pch != nullptr) {
            mom_inertie = atof(pch);
            pch = strtok(nullptr, " ;");
        }
        if (pch != nullptr) {
            distance = atof(pch);
        }

        // Afficher les valeurs des variables
        cout << "m_cabine: " << m_cabine << endl;
        cout << "m_contrepoids: " << m_contrepoids << endl;
        cout << "r_poulie: " << r_poulie << endl;
        cout << "vitesse_max: " << vitesse_max << endl;
        cout << "duree_acceleration: " << duree_acceleration << endl;
        cout << "couple_moteur: " << couple_mot << endl;
        cout << "t_cabine: " << t_cabine << endl;
        cout << "t_contrepoids: " << t_contrepoids << endl;
        cout << "v_angulaire: " << a_angulaire << endl;
        cout << "mom_inertie: " << mom_inertie << endl;
        cout << "distance: " << distance << endl;


        while (true) { // Boucle pour répéter le menu après chaque calcul/choix
            cout << "\n=== MENU PRINCIPAL (.csv active) ===\n";
            cout << "1. Calculer la tension\n";
            cout << "2. Calculer le couple moteur\n";
            cout << "3. Calculer la puissance moteur\n";
            cout << "4. Calculer le rayon de la poulie\n";
            cout << "5. Calculer la vitesse de rotation\n";
            cout << "6. Calculer le temps de montee/descente\n";
            cout << "7. Calculer l'acceleration\n";
            cout << "8. Executer les tests\n";
            cout << "9. Quitter\n";
            cout << "10. Arreter d'utiliser le fichier .csv\n";
            cout << "Entrez votre choix : ";
            cin >> choix_donne;

            if (choix_donne == 10) {
                cout << "Arrêt du fichier .csv\n";
                break;
            }

            if (choix_donne == 9) {
                cout << "Programme termine.\n";
                break;
            }

            switch (choix_donne) {
            case 1: {
                float a_angulaire2 = a_angulaire,
                    mom_inertie2 = mom_inertie,
                    m_cabine2 = m_cabine,
                    m_contrepoids2 = m_contrepoids,
                    r_poulie2 = r_poulie,
                    puissance_moteur2 = puissance_mot,
                    vitesse_max2 = vitesse_max;

                int choix_tension, choix_result;

                cout << "Donner la formule a utiliser en fonction des valeurs que vous avez (0 = acceleration et masse, 1 = les moments de force, les moments d'inertie et acceleration) : ";
                cin >> choix_tension;
                cout << "Donner le resultat de sortie (0 = tension cabine, 1 = tension contrepoids, 2 = les deux) : ";
                cin >> choix_result;

                Tensions result = Calcule_Tension(choix_tension, choix_result, m_cabine2, m_contrepoids2, a_angulaire2, mom_inertie2, r_poulie2, puissance_moteur2, vitesse_max2);
                cout << "Tension cabine: " << result.cabine << " N, Tension contrepoids: " << result.contrepoids << " N\n";
                break;
            }

            case 2: {
                float tension_cabine2 = t_cabine, tension_contrepoids2 = t_contrepoids, alpha2 = a_angulaire, moments_dinertie2 = mom_inertie, rayon2 = r_poulie, p_moteur2 = puissance_mot, vitesse2 = vitesse_max;
                int choix_couple;

                cout << "Choisissez (0 = couple moteur par puissance, 1 = couple moteur par tensions) : ";
                cin >> choix_couple;
                cout << "Couple moteur : " << couple_moteur(choix_couple, tension_cabine2, tension_contrepoids2, alpha2, moments_dinertie2, rayon2, p_moteur2, vitesse2) << " Nm\n";
                break;
            }

            case 3: {
                float couple_mot2 = couple_mot, vitesse2 = vitesse_max, rayon2 = r_poulie;
                cout << "Puissance moteur : " << puissance_moteur(couple_mot2, vitesse2, rayon2) << " W\n";
                break;
            }

            case 4: {
                float vitesse2 = vitesse_max, vitesse_angulaire2 = a_angulaire;
                cout << "Rayon de la poulie : " << rayon_poulie(vitesse2, vitesse_angulaire2) << " m\n";
                break;
            }

            case 5: {
                float vitesse_angulaire2 = a_angulaire;
                cout << "Vitesse de rotation : " << vitesse_rotation(vitesse_angulaire2) << " tr/min\n";
                break;
            }

            case 6: {
                float distance2 = distance, vitesse2 = vitesse_max;
                cout << "Temps de montee/descente : " << temps_montee_and_descente(distance2, vitesse2) << " s\n";
                break;
            }

            case 7: {
                float masse_cabine2 = m_cabine, masse_contrepoids2 = m_contrepoids, tension_cabine2 = t_cabine, tension_contrepoids2 = t_contrepoids, vitesse2 = vitesse_max;
                int choix_acc;

                cout << "Choisissez (0 = cabine, 1 = contrepoids, 2 = aucun) : ";
                cin >> choix_acc;
                cout << "Acceleration : " << acceleration(choix_acc, masse_contrepoids2, masse_cabine2, tension_contrepoids2, tension_cabine2, vitesse2) << " m/s²\n";
                break;
            }

            case 8:
                test_fonction();
                break;

            default:
                cout << "Choix invalide, veuillez reessayer.\n";
            }
        }
    }
    else {
        cout << "Impossible d'ouvrir le fichier." << endl;
    }
}

Tensions Calcule_Tension(int choix_formule, int choix_donnees, float masse_cabine, float masse_contrepoids, float alpha, float moments_dinertie, float rayon, float p_moteur, float vitesse) {
    double tension_cabine, tension_contrepoids;

    if (choix_formule == choix_calcul_tension_avec_somme_force) {
        tension_cabine = masse_cabine * (alpha + g);
        tension_contrepoids = masse_contrepoids * (g - alpha);

        if (choix_donnees == choix_tension_cabine) {
            return Tensions{ tension_cabine, 0 };
        }
        else if (choix_donnees == choix_tension_contrepoids) {
            return Tensions{ 0, tension_contrepoids };
        }
        else if (choix_donnees == choix_des_deux_tension) {
            return Tensions{ tension_cabine, tension_contrepoids };
        }
        else {
            cout << "La valeur du choix est invalide. Veuillez reessayer.";
            return { 0, 0 };
        }
    }

    if (choix_formule == choix_calcul_tension_avec_cm) {
        tension_cabine = masse_contrepoids * (g - alpha) - (p_moteur / moments_dinertie);
        tension_contrepoids = (p_moteur + (moments_dinertie * masse_cabine) * (alpha + g)) / moments_dinertie;

        if (choix_donnees == choix_tension_cabine) {
            return Tensions{ tension_cabine, 0 };
        }
        else if (choix_donnees == choix_tension_contrepoids) {
            return Tensions{ 0, tension_contrepoids };
        }
        else if (choix_donnees == choix_des_deux_tension) {
            return Tensions{ tension_cabine, tension_contrepoids };
        }
        else {
            cout << "La valeur du choix est invalide. Veuillez reessayer.";
            return Tensions{ 0, 0 };
        }
    }

    cout << "La valeur du choix pour la formule a utiliser est invalide. Veuillez reessayer.";
    return { 0, 0 };
}

double couple_moteur(int choix, float tension_cabine, float tension_contrepoids, float alpha, float moments_dinertie, float rayon, float p_moteur, float vitesse) {
    if (choix == 0) {
        return (p_moteur * rayon) / vitesse;
    }
    else if (choix == 1) {
        return ((moments_dinertie * alpha) / rayon) * (tension_contrepoids - tension_cabine) * rayon;
    }
    else {
        cout << "La valeur du choix est invalide. Veuillez reessayer.";
        return 0;
    }
}

double puissance_moteur(float couple_mot, float vitesse, float rayon) {
    return couple_mot * (vitesse / rayon);
}

double rayon_poulie(float vitesse, float vitesse_angulaire) {
    return vitesse / vitesse_angulaire;
}

double vitesse_rotation(float vitesse_angulaire) {
    return (vitesse_angulaire * 30) / M_PI;
}

double temps_montee_and_descente(float distance, float vitesse) {
    return distance / vitesse;
}

double acceleration(int choix, float masse_contrepoids, float masse_cabine, float tension_contrepoids, float tension_cabine, float vitesse) {
    if (choix == 0) {
        return (tension_cabine - masse_cabine * g) / masse_cabine;
    }
    else if (choix == 1) {
        return (tension_contrepoids - masse_contrepoids * g) / masse_contrepoids;
    }
    else if (choix == 2) {
        return 0; // A faire voir si on le fait vraiment
    }
    else {
        cout << "La valeur du choix est invalide. Veuillez reessayer.";
        return 0;
    }
}

void test_fonction() {
    try {
        Tensions t1 = Calcule_Tension(0, 0, 350, 100, 0.3, 0, 0, 0, 0);
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
    catch (...) {
        cerr << " Erreur lors de l'execution des tests !" << endl;
    }
}


void sfml_simu(void) {
    unsigned int width = 1600;
    unsigned int height = 900;
    sf::RenderWindow window(sf::VideoMode({ width, height }), "Ascenseur SFML");
    window.setFramerateLimit(60);

    sf::Font font;
    std::string fontPath = "../dependances_exterieurs/fonts/Roboto-BlackItalic.ttf";

    if (!std::filesystem::exists(fontPath)) {
        std::cerr << "Le fichier " << fontPath << " nexiste pas!" << std::endl;
    }
    else {
        std::cout << "Le fichier " << fontPath << " existe!" << std::endl;
        if (!font.openFromFile(fontPath)) {
            std::cerr << "Erreur lors du chargement de la police!" << std::endl;
        }
        else {
            std::cout << "Police chargee avec succes!" << std::endl;
        }
    }


    //fenetre help
    sf::RectangleShape helpBox(sf::Vector2f(400, 200));
    helpBox.setFillColor(sf::Color(0, 0, 0, 150)); // Noir transparent
    helpBox.setPosition({ 50.f, 20.f });

    sf::Text helpText(font);
    helpText.setCharacterSize(18);
    helpText.setFillColor(sf::Color::White);
    helpText.setString("Touches :\n[H] - Aide\n[Up] - Monter\n[Down] - Descendre\n[Esc] - Quitter");
    helpText.setPosition({ 70.f, 40.f });

    bool showHelp = false; // Variable pour gérer l'affichage de l'aide

    // Moteur (Poulie)
    sf::CircleShape moteur(120.f);
    moteur.setOrigin({ 120.f, 120.f });
    moteur.setPosition({ 800.f, 200.f });
    moteur.setFillColor(sf::Color::White);
    moteur.setOutlineThickness(3);
    moteur.setOutlineColor(sf::Color::Black);

    // Cabine
    sf::RectangleShape cabine({ 120.f,160.f });
    cabine.setOrigin({ 60.f, 80.f });
    cabine.setPosition({ 920.f, 800.f }); // Position initiale
    cabine.setFillColor(sf::Color::White);
    cabine.setOutlineThickness(3);
    cabine.setOutlineColor(sf::Color::Black);

    // Contrepoids
    sf::RectangleShape contrepoids({ 80.f, 140.f });
    contrepoids.setOrigin({ 40.f, 70.f });
    contrepoids.setPosition({ 680.f, 400.f }); // Position initiale
    contrepoids.setFillColor(sf::Color::White);
    contrepoids.setOutlineThickness(3);
    contrepoids.setOutlineColor(sf::Color::Black);

    // Câbles
    sf::RectangleShape cable1({ 3.f, 520.f }); // Câble cabine → Poulie
    cable1.setOrigin({ 1.5f, 0.f });
    cable1.setPosition({ 921.f, 200.f });
    cable1.setFillColor(sf::Color::Black);

    sf::RectangleShape cable2({ 3.f, 150.f }); // Câble contrepoids → Poulie
    cable2.setOrigin({ 1.5f, 0.f });
    cable2.setPosition({ 680.f, 200.f });
    cable2.setFillColor(sf::Color::Black);

    // Limites
    const float LIMITE_HAUT = 400.f;  // Ne pas dépasser la poulie
    const float LIMITE_BAS = 800.f;   // Niveau du sol
    float vitesse = 5.0f; // Vitesse de déplacement

    while (window.isOpen()) {
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
                return;
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    window.close();
                    return;
                }
                if (keyPressed->scancode == sf::Keyboard::Scancode::H) {
                    showHelp = !showHelp; // Toggle affichage aide
                }
            }
        }

        // Mouvement de la cabine et du contrepoids
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) { // Monte
            if (cabine.getPosition().y > LIMITE_HAUT) {
                cabine.move({ 0.f, -vitesse });
                contrepoids.move({ 0.f, vitesse });
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) { // Descend
            if (cabine.getPosition().y < LIMITE_BAS) { // Vérification de la limite basse
                cabine.move({ 0.f, vitesse });
                contrepoids.move({ 0.f, -vitesse });
            }
        }

        // Mise à jour des câbles pour suivre les mouvements
        cable1.setSize({ 3.f, cabine.getPosition().y - 200.f });
        cable1.setPosition({ 921.f, 200.f });

        cable2.setSize({ 3.f, contrepoids.getPosition().y - 200.f });
        cable2.setPosition({ 680.f, 200.f });

        // Affichage
        window.clear(sf::Color::White);
        window.draw(moteur);
        window.draw(cable1);
        window.draw(cable2);
        window.draw(cabine);
        window.draw(contrepoids);


        if (showHelp) {
            window.draw(helpBox);
            window.draw(helpText);
        }
        window.display();
    }
}

