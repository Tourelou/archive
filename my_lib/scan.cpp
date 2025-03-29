#include <iostream>
#include <unistd.h>	// chdir, getcwd
#include <libgen.h>	// basename

bool scanVolume(const std::string& directory) {
	// Changer le répertoire de travail
	if (chdir(directory.c_str()) != 0) {
		std::cerr << "Impossible d'accéder au répertoire " << directory << std::endl;
		return false;
	}
	char buffer[PATH_MAX];
	if (getcwd(buffer, PATH_MAX) == nullptr) {
		std::cerr << "Impossible d'obtenir le répertoire courant" << std::endl;
		return false;
	}
	// Utiliser basename pour obtenir la dernière partie du chemin
	char* dirName = basename(buffer);
	std::string filename = "/Users/danv/Documents/Archives/Volumes/";
	filename.append(dirName).append(".txt");

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
