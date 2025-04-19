#include <iostream>
#include <sys/stat.h>	// Pour directoryExists
#include <cstdlib> // Pour getenv - expandHome
#include <string>
#include <unistd.h> // Pour access() (optionnel)

#include "includes/mkdir_p.hpp"
#include "my_lib/argparse_archive.hpp" // Parse la ligne de commande
#include "my_lib/fr.en_strings.hpp"
#include "my_lib/getFrancais.hpp"
#include "my_lib/find.hpp"
#include "my_lib/scan.hpp"

bool langFranc = false;

void prt_message(const std::string &m) {
	std::cout << m << std::endl;
}

std::string expandHome(const std::string& path) {
	const std::string homeEnv = "$HOME";
	if (path.substr(0, homeEnv.size()) == homeEnv) {
		const char* home = std::getenv("HOME");
		if (home) {
			// Remplace le '$HOME' par le chemin réel
			return std::string(home) + path.substr(homeEnv.size());
		}
	}
	return path; // Renvoie le chemin tel quel s'il ne commence pas par '$HOME'
}

bool Exists_or_createDirectory(const std::string& basePath) {
	if (dirExists(basePath)) return true;
	return createDir(basePath);
}

int main(int argc, char *argv[]) {

	std::string baseArchPath = "$HOME/Documents/Archives/Volumes";
	baseArchPath = expandHome(baseArchPath);
	langFranc = getFrancais();

		// Set les éléments pour parser avec argparse.hpp
	argparseBase arg({.version = "version 2025-04-19"});

	if (langFranc) {
		arg.description = fr_message_description;
		arg.usage = fr_message_usage;
		arg.helpMsg = fr_message_aide;
	}
	else {
		arg.description = en_message_description;
		arg.usage = en_message_usage;
		arg.helpMsg = en_message_aide;
	}

	int ret = parse(arg, argc, argv);
	if (ret == retcode::HELP_VERSION) return 0;

	std::string optionString;
	switch (ret) {
		case OK:
			optionString = std::get<1>(arg.rtn_data);
			switch (std::get<0>(arg.rtn_data)) {
				case 1:
					if(dirExists(baseArchPath)) findPattern(baseArchPath, optionString);
					else {
						if (langFranc) prt_message("Aucune structure de répertoires où sont les fichiers .txt.");
						else prt_message("No directory structure where .txt files are stored.");
						return 10;
					}
					break;
		
				case 2:
					if (dirExists(baseArchPath)) return !scanVolume(baseArchPath, optionString);
					else {
						if (createDir(baseArchPath)) return !scanVolume(baseArchPath, optionString);
						else {
							if (langFranc) std::cout << "Problème: Le répertoire " << baseArchPath
									<< " n'existe pas, et je ne peux le créer." << std::endl;
							else std::cout << "Problem: The folder " << baseArchPath
									<< " doesn't exists, and I can't create it." << std::endl;
							return 10;
						}
					}
					break;

				default:
					break;
			}
			break;

		case TROP_ARGS:
			if (langFranc) {
				std::cout << "Trop d'arguments" << std::endl;
				prt_message(fr_message_usage);
			}
			else {
				std::cout << "Too many arguments" << std::endl;
				prt_message(en_message_usage);
			}
			return 1;
			break;

		case MANQUE_ARGS:
			if (langFranc) {
				std::cout << "Il manque des arguments" << std::endl;
				prt_message(fr_message_usage);
			}
			else {
				std::cout << "Arguments missing" << std::endl;
				prt_message(en_message_usage);
			}
			return 1;
			break;

		case ERROR:
			if (langFranc) prt_message(fr_message_usage);
			else prt_message(en_message_usage);
			return 1;

		default:
			break;
	}
	return 0;
}
