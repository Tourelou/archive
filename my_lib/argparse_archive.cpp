#include "argparse_archive.hpp"

std::vector<const char *> longOptions = {"--find", "--scan"};
std::vector<char> shortOptions = {'f', 's'};

int parse(struct argparseBase &Base, int argc, char* argv[]) { // return 0 = OK, 1 = help-version, 2+ erreur

	if (Base.progName == "") {
		std::string s = argv[0];
		Base.progName = s.substr(s.find_last_of("/\\") + 1);
	}
	if (Base.helpMsg == "") {
		Base.helpMsg = Base.progName;
		if (Base.description != "") Base.helpMsg += ": " + Base.description;
		if (Base.version != "") Base.helpMsg += ", " + Base.version;
		if (Base.usage != "") Base.helpMsg += "\n---\n" + Base.usage;
	}
	// Début du parsing
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-h") == 0) {
			std::cout << Base.usage << std::endl;
			return retcode::HELP_VERSION;
		}
		if (strcmp(argv[i], "--help") == 0) {
			std::cout << Base.helpMsg << std::endl;
			return retcode::HELP_VERSION;
		}
		if (strcmp(argv[i], "-ver") == 0) {
			std::cout << Base.progName << ": ";
			if (Base.version != "") std::cout << Base.version << std::endl;
			else std::cout << "Version nondisponible." << std::endl;
			return retcode::HELP_VERSION;
		}
		if (strcmp(argv[i], "--version") == 0) {
			std::cout << Base.progName << ": ";
			if (Base.description != "") std::cout << Base.description << ", ";
			else std::cout << "Description nondisponible, ";
			if (Base.version != "") std::cout << Base.version << std::endl;
			else std::cout << "Version nondisponible." << std::endl;
			return retcode::HELP_VERSION;
		}

		if (argc < 3) return retcode::MANQUE_ARGS;
		if (argc > 3) return retcode::TROP_ARGS;

		std::string analyse = argv[1];
		if (analyse == "-f" || analyse == "--find") {
			Base.rtn_data = std::make_tuple(1, argv[2]);
			return retcode::OK;
		}
		else if (analyse == "-s" || analyse == "--scan") {
			Base.rtn_data = std::make_tuple(2, argv[2]);
			return retcode::OK;
		}
		else {
			std::cout << "illegale option: " << argv[1] << std::endl;
			return retcode::ERROR;
		}
	}
	return retcode::OK;
}
