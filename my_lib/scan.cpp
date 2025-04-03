#include <iostream>
#include <unistd.h>	// chdir, getcwd
#include <libgen.h>	// basename
#ifdef __linux__
    #include <linux/limits.h>
#endif

#include "getFrancais.hpp"

bool scanVolume(const std::string& path, const std::string& directory) {
	// Changer le répertoire de travail
	if (chdir(directory.c_str()) != 0) {
		if (langFranc) std::cerr << "Impossible d'accéder au répertoire " << directory << std::endl;
		else std::cerr << "Can't access folder " << directory << std::endl;
		return false;
	}
	char buffer[PATH_MAX];
	if (getcwd(buffer, PATH_MAX) == nullptr) {
		if (langFranc) std::cerr << "Impossible d'obtenir le répertoire courant" << std::endl;
		else std::cerr << "Can't get the current directory" << std::endl;
		return false;
	}
	// Utiliser basename pour obtenir la dernière partie du chemin
	char* dir_filename = basename(buffer);
	std::string arcFilename = "";
	arcFilename.append(path).append("/").append(dir_filename).append(".txt");

	// Exécuter la commande 'find' et rediriger la sortie vers le fichier
	std::string command = "find . -type f > \"" + arcFilename + "\"";
	int result = system(command.c_str());
	
	if (result == 0) {
		if (langFranc) std::cout << "Scan terminé. Résultats sauvegardés dans «" << path << "»" << std::endl;
		else std::cout << "Scan completed. Results saved to «" << path << "»" << std::endl;
		return true;
	} else {
		if (langFranc) std::cerr << "Erreur lors de l'exécution de la commande find" << std::endl;
		else std::cerr << "Problems to execute the find command" << std::endl;
		return false;
	}
}
