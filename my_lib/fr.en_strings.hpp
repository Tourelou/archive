#ifndef __STRINGS_SEL__
	#define __STRINGS_SEL__

	#include <string>

	std::string message_version = "version 2025-04-01";

	std::string fr_message_description = "Trouve un motif ou scan un volume vers un fichier texte";

	std::string fr_message_usage = "Usage: archive [-h] [-ver] <-f|--find motif> | <-s|--scan volume à scanner>";

	std::string fr_message_aide = // option --help
		fr_message_usage+"\n"
		"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"
		+fr_message_description+".\n""\n"
		"Options:\n"
		" -f,   --find     <motif regex>    Motif à chercher: Mettre entre '...'\n"
		"     ou\n"
		" -s,   --scan     <volume à scanner> Chemin du répertoire à scanner.\n\n"
		" -ver, --version  Donne les info de version du programme.\n"
		" -h,   --help     Montre ce message d'aide et termine.\n"
		"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -";

	std::string fr_message_exclude =
		"Pour les flags «f|d», il sont mutuellement exclusif. C'est un ou c'est l'autre.";

	std::string fr_message_erreur =
		"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"
		"- - ATTENTION - - ATTENTION - - ATTENTION - - ATTENTION - - ATTENTION - -\n"
		"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"
		"Il faut faire: archive <-f|--find motif>\n"
		"               ou bien\n"
		"               archive <-s|--scan volume à scanner>\n"
		"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"+fr_message_aide;

//	------------- string en anglais -------------------

	std::string en_message_description = "Find a pattern or scan volume/folder to text file";

	std::string en_message_usage = "Usage: archive [-h] [-ver] <-f|--find pattern> | <-s|--scan volume to scan>";

	std::string en_message_aide = // option --help
		en_message_usage+"\n"
		"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"
		+en_message_description+".\n""\n"
		"Options:\n"
		" -f,   --find     <regex pattern>    Pattern to search: Put in single cote '...'\n"
		"     or\n"
		" -s,   --scan     <volume to scan> Path to volume/folder to scan.\n\n"
		" -ver, --version  Program info version.\n"
		" -h,   --help     Help message the exit.\n"
		"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -";

	std::string en_message_exclude =
		"For «f|d» flags, they are mutually exclusive. It,S one or the other.";

	std::string en_message_erreur =
		"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"
		"- -  WARNING  - -  WARNING  - -  WARNING  - -  WARNING  - -  WARNING  - -\n"
		"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"
		"It's should be: archive <-f|--find pattern>\n"
		"                or\n"
		"                archive <-s|--scan volume to scan>\n"
		"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"+en_message_aide;

	#endif	// __STRINGS_SEL__
