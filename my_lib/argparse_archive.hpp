#ifndef __ARGPARSE_ARCHIVE__
	#define __ARGPARSE_ARCHIVE__

	#include <iostream>
	#include <string>
	#include <cstring>
	#include <vector>
	#include <tuple>

	struct argparseBase // Base class structure
	{
		std::string progName;		// Si absent, contruit par argv[0]
		std::string version;		// ex.: "version 2024-02-06 Beta"
		std::string description;	// ex.: "Programme qui fait ceci"
		std::string usage;			// ex.: "prg [-fnh] <-i int> ..." - option -h
		std::string helpMsg;		// Si absent, construit avec le 4 autres - option --help

		std::tuple<int, std::string> rtn_data;
	};

	int parse(struct argparseBase&, int argc, char* argv[]);

	enum retcode { OK, HELP_VERSION, ERROR, TROP_ARGS, MANQUE_ARGS};

	#endif
