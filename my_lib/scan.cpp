#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <ctime>
#include <cstdlib>

bool scanVolume(const std::string& directory) {
	// Changer le répertoire de travail
	if (chdir(directory.c_str()) != 0) {
		std::cerr << "Impossible d'accéder au répertoire " << directory << std::endl;
		return false;
	}
	// Obtenir la date actuelle pour le nom du fichier
	time_t now = time(0);
	struct tm* timeinfo = localtime(&now);
	char buffer[80];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
	std::string filename = "/Users/danv/Documents/Archives/Volumes/" + std::string(buffer) + ".txt";

	// Exécuter la commande 'find' et rediriger la sortie vers le fichier
	std::string command = "find . -type f > \"" + filename + "\"";
	int result = system(command.c_str());
	
	if (result == 0) {
		std::cout << "Scan terminé. Résultats sauvegardés dans «" << filename << "»" << std::endl;
		return true;
	} else {
		std::cerr << "Erreur lors de l'exécution de la commande find" << std::endl;
		return false;
	}
}
