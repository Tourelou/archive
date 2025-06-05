#include <iostream>
#include <sys/stat.h>	// Pour directoryExists
#include <cstdlib> // Pour getenv - expandHome
#include <string>
#include <unistd.h> // Pour access() (optionnel)

#include "includes/mkdir_p.hpp"
#include "my_lib/argparse_archive.hpp" // Parse la ligne de commande
#include "my_lib/arc_locale.hpp"
#include "my_lib/find.hpp"
#include "my_lib/scan.hpp"

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

	set_arc_locale();

	std::string baseArchPath = "$HOME/Documents/Archives/Volumes";
	baseArchPath = expandHome(baseArchPath);

	// Set les éléments pour parser avec argparse.hpp
	argparseBase arg({.version = "version 2025-06-05"});

	arg.description = arc_locale("message_description");
	arg.usage = arc_locale("message_usage");
	arg.helpMsg = arc_locale("message_usage")+"\n"
	"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"
	+arc_locale("message_description")+".\n""\n"+arc_locale("message_aide");
	
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
						std::cout << arc_locale("message_no_structure") << std::endl;
						return 10;
					}
					break;
		
				case 2:
					if (dirExists(baseArchPath)) return !scanVolume(baseArchPath, optionString);
					else {
						if (createDir(baseArchPath)) return !scanVolume(baseArchPath, optionString);
						else {
							printf(arc_locale("gros_probleme_dir").c_str(), baseArchPath.c_str());
							return 10;
						}
					}
					break;
				default:
					break;
			}
			break;

		case TROP_ARGS:
			std::cout << arc_locale("message_trop_arguments") << std::endl;
			std::cout << arc_locale("message_erreur") << std::endl;
			return 1;
			break;

		case MANQUE_ARGS:
			std::cout << arc_locale("message_manque_arguments") << std::endl;
			std::cout << arc_locale("message_erreur") << std::endl;
			return 1;
			break;

		case ERROR:
			std::cout << arc_locale("message_erreur") << std::endl;
			return 1;

		default:
			break;
	}
	return 0;
}
