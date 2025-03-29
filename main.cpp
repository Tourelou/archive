#include <iostream>

#include "argparse.hpp" // Parse la ligne de commande
#include "my_lib/find.hpp"
#include "my_lib/scan.hpp"

std::string message_version = "version 2025-01-11";

std::string message_description = "Trouve un motif ou scan un volume vers un fichier texte";

std::string message_usage = "Usage: archive [-h] [-ver] <-f|--find motif> | <-s|--scan volume à scanner>";

std::string message_aide = // option --help
	message_usage+"\n"
	"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"
	+message_description+".\n""\n"
	"Options:\n"
	" -f,   --find     <regex pattern>    Motif à chercher: Mettre entre '...'\n"
	"     ou\n"
	" -s,   --scan     <volume à scanner> Chemin du répertoire à scanner.\n\n"
	" -ver, --version  Donne les info de version du programme.\n"
	" -h,   --help     Montre ce message d'aide et termine.\n"
	"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -";

std::string message_exclude =
	"Pour les flags «f|d», il sont mutuellement exclusif. C'est un ou c'est l'autre.";

std::string message_erreur =
	"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"
	"- - ATTENTION - - ATTENTION - - ATTENTION - - ATTENTION - - ATTENTION - -\n"
	"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"
	"Il faut faire: archive <-f|--find motif>\n"
	"               ou bien\n"
	"               archive <-s|--scan volume à scanner>\n"
	"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"+message_aide;
std::string find_string = "";
std::string scan_string = "";

void prt_message(std::string &m) {
	std::cout << m << std::endl;
}

int main(int argc, char *argv[]) {

	// Set les éléments pour parser avec argparse.hpp
	argparse arg({.version = message_version, .description = message_description, 
									.usage = message_usage, .helpMsg = message_aide});

	if (! arg.addOption({.varPtr = &find_string, .shortOption = "-f", .longOption = "--find",
							.varType = def::STRING})) return 1;
	if (! arg.addOption({.varPtr = &scan_string, .shortOption = "-s", .longOption = "--scan",
							.varType = def::STRING})) return 1;

	int ret = arg.parse(argc, argv);

	if (arg.argPos_c > 0) {
		std::cout << "Trop d'arguments" << std::endl;
		prt_message(message_usage);
		return 1; }

	if (ret == retcode::ERROR) { prt_message(message_usage); return 1;}
	if (ret == retcode::HELP_VERSION) return 0;

	if (find_string != "") {
		if (scan_string != "") {
			prt_message(message_exclude);
			return 1;
		}
		else findPattern(find_string);
	}

	if (find_string == "") {
		if (scan_string == "") {
			prt_message(message_erreur);
			return 1;
		}
		else return !scanVolume(scan_string);
	}
	return 0;
}
