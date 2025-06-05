#include <iostream>
#include <unistd.h>	// chdir, getcwd
#include <libgen.h>	// basename
#ifdef __linux__
	#include <linux/limits.h>
#endif

#include "arc_locale.hpp"

bool scanVolume(const std::string& path, const std::string& directory) {
	// Changer le répertoire de travail
	if (chdir(directory.c_str()) != 0) {
		std::cerr << arc_locale("err_acces_dir") << directory << std::endl;
		return false;
	}
	char buffer[PATH_MAX];
	if (getcwd(buffer, PATH_MAX) == nullptr) {
		std::cerr << arc_locale("err_get_pwd") << std::endl;
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
		printf(arc_locale("info_scan").c_str(), path.c_str());
		return true;
	} else {
		std::cerr << arc_locale("err_cmd_find") << std::endl;
		return false;
	}
}
