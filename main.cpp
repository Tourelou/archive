#include <iostream>

#include "argparse.hpp" // Parse la ligne de commande
#include "my_lib/fr.en_strings.hpp"
#include "my_lib/getFrancais.hpp"
#include "my_lib/find.hpp"
#include "my_lib/scan.hpp"

std::string find_string = "";
std::string scan_string = "";
bool langFranc = false;

void prt_message(std::string &m) {
	std::cout << m << std::endl;
}

int main(int argc, char *argv[]) {

	langFranc = getFrancais();

	// Tout d'abord, est-ce que le répertoire existe ?

	// Set les éléments pour parser avec argparse.hpp
	argparse arg({.version = message_version});

	if (langFranc) {
		arg.Base.description = fr_message_description;
		arg.Base.usage = fr_message_usage;
		arg.Base.helpMsg = fr_message_aide;
	}
	else {
		arg.Base.description = en_message_description;
		arg.Base.usage = en_message_usage;
		arg.Base.helpMsg = en_message_aide;
	}

	if (! arg.addOption({.varPtr = &find_string, .shortOption = "-f", .longOption = "--find",
							.varType = def::STRING})) return 1;
	if (! arg.addOption({.varPtr = &scan_string, .shortOption = "-s", .longOption = "--scan",
							.varType = def::STRING})) return 1;

	int ret = arg.parse(argc, argv);

	if (arg.argPos_c > 0) {
		if (langFranc) {
			std::cout << "Trop d'arguments" << std::endl;
			prt_message(fr_message_usage);
		}
		else {
			std::cout << "Too many arguments" << std::endl;
			prt_message(en_message_usage);
		}
		return 1; }

	if (ret == retcode::ERROR) {
		if (langFranc) prt_message(fr_message_usage);
		else prt_message(en_message_usage);
		return 1;
	}
	if (ret == retcode::HELP_VERSION) return 0;

	if (find_string != "") {
		if (scan_string != "") {
			if (langFranc) prt_message(fr_message_exclude);
			else prt_message(en_message_exclude);
			return 1;
		}
		else findPattern(find_string);
	}

	if (find_string == "") {
		if (scan_string == "") {
			if (langFranc) prt_message(fr_message_erreur);
			else prt_message(en_message_erreur);
			return 1;
		}
		else return !scanVolume(scan_string);
	}
	return 0;
}
