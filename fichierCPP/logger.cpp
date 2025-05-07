#include "Logger.h"


// Constructeur: appelé quand on crée un nouvel objet Logger
Logger::Logger(const std::string& filename) : filename(filename) {
    // Ouvre un fichier pour écriture (mode append: ajoute à la fin du fichier)
    logFile.open(filename, std::ios::out | std::ios::app);

    // Vérifie si le fichier s'est bien ouvert
    if (!logFile.is_open()) {
        // Affiche un message d'erreur si l'ouverture a échoué
        std::cerr << "Erreur d'ouverture du fichier de log: " << filename << std::endl;
        return;
    }

    // Si le fichier est vide (position = 0), ajoute un en-tête
    if (logFile.tellp() == 0) {
        logFile << "Level,Message\n";  // Format CSV: niveau,message
        logFile.flush();  // Force l'écriture immédiate des données sur le disque
    }
}

// Destructeur: appelé quand l'objet Logger est détruit
Logger::~Logger() {
    // Ferme proprement le fichier s'il est encore ouvert
    if (logFile.is_open()) {
        logFile.close();
    }
}

// Méthode pour écrire un message dans le fichier de log
void Logger::log(LogLevel level, const std::string& message) {
    // Utilise un mutex pour éviter que plusieurs threads écrivent en même temps
    std::lock_guard<std::mutex> lock(logMutex);

    // Vérifie si le fichier est bien ouvert
    if (!logFile.is_open()) {
        std::cerr << "Erreur : fichier de log non ouvert." << std::endl;
        return;
    }

    // Écrit le niveau et le message au format CSV
    logFile << logLevelToString(level) << "," << message << "\n";
    logFile.flush();  // Force l'écriture immédiate pour éviter de perdre des logs
}

// Convertit l'énumération LogLevel en texte lisible
std::string Logger::logLevelToString(LogLevel level) {
    // Selon le niveau de log passé, renvoie une chaîne correspondante
    switch (level) {
    case LogLevel::INFO:    return "INFO";     // Information normale
    case LogLevel::WARNING: return "WARNING";  // Avertissement
    case LogLevel::ERROR:   return "ERROR";    // Erreur
    default:                return "UNKNOWN";  // Niveau inconnu
    }
}
