#ifndef __STRINGS_SEL__
	#define __STRINGS_SEL__

	#include <map>
	#include <string>

	std::string get_lang_from_env();
	void set_arc_locale();
	std::string arc_locale(const std::string&);

	const std::map<std::string, std::map<std::string, std::string>> translations = {
		{"message_description", {
			{"en", "Find a pattern or scan volume/folder to text file"},
			{"fr", "Trouve un motif ou scan un volume vers un fichier texte"},
			{"es", "Encuentra un patrón o escanea un volumen a un archivo de texto"}}
		},
		{"message_usage", {
			{"en", "Usage: archive [-h] [-ver] <-f|--find pattern> | <-s|--scan volume to scan>"},
			{"fr", "Usage: archive [-h] [-ver] <-f|--find motif> | <-s|--scan volume à scanner>"},
			{"es", "Usage: archive [-h] [-ver] <-f|--find patrón> | <-s|--scan volumen a escanear>"}}
		},
		{"message_exclude", {
			{"en", "For «f|d» flags, they are mutually exclusive. It,S one or the other."},
			{"fr", "Pour les flags «f|d», il sont mutuellement exclusif. C'est un ou c'est l'autre."},
			{"es", "Para los flags «f|d», son mutuamente exclusivos. Es uno o el otro."}}
		},
		{"message_no_structure", {
			{"en", "No directory structure where .txt files are stored."},
			{"fr", "Aucune structure de répertoires où sont les fichiers .txt."},
			{"es", "No hay estructura de directorios donde están los archivos .txt."}}
		},
		{"message_trop_arguments", {
			{"en", "Too many arguments"},
			{"fr", "Trop d'arguments"},
			{"es", "demasiados argumentos"}}
		},
		{"message_manque_arguments", {
			{"en", "Arguments missing"},
			{"fr", "Il manque des arguments"},
			{"es", "Falta de argumentos"}}
		},
		{"gros_probleme_dir", {
			{"en", "Problem: The folder '%s' doesn't exists, and I can't create it.\n"},
			{"fr", "Problème: Le répertoire '%s' n'existe pas, et je ne peux le créer.\n"},
			{"es", "Problema: El directorio '%s' no existe, y no puedo crearlo.\n"}}
		},
//	Message de find.cpp ===>
		{"err_open_file", {
			{"en", "Can't open file "},
			{"fr", "Impossible d'ouvrir le fichier "},
			{"es", "No se puede abrir el archivo "}}
		},
		{"err_open_dir", {
			{"en", "Can't open dir "},
			{"fr", "Impossible d'ouvrir le répertoire "},
			{"es", "No se puede abrir el directorio "}}
		},
		{"err_cd_dir", {
			{"en", "Can't chdir to path "},
			{"fr", "Impossible de changer de répertoire vers "},
			{"es", "No se puede cambiar de directorio a "}}
		},
		{"info_find", {
			{"en", "Pattern «%s» in %s/*.txt\n"},
			{"fr", "Le motif «%s» dans %s/*.txt\n"},
			{"es", "El motivo «%s» en %s/*. txt\n"}}
		},
//	Message de find.cpp <===
//	Message de scan.cpp ===>
		{"err_acces_dir", {
			{"en", "Can't access folder "},
			{"fr", "Impossible d'accéder au répertoire "},
			{"es", "No se puede acceder al directorio "}}
		},
		{"err_get_pwd", {
			{"en", "Can't get the current directory"},
			{"fr", "Impossible d'obtenir le répertoire courant"},
			{"es", "No se puede obtener el directorio actual"}}
		},
		{"err_cmd_find", {
			{"en", "Problems to execute the find command "},
			{"fr", "Erreur lors de l'exécution de la commande find."},
			{"es", "Error al ejecutar el comando find."}}
		},
		{"info_scan", {
			{"en", "Scan completed. Results saved to «%s»\n"},
			{"fr", "Scan terminé. Résultats sauvegardés dans «%s»\n"},
			{"es", "Escaneo terminado. Resultados guardados en «%s»\n"}}
		},
//	Message de scan.cpp <===
		{"message_aide", {
			{"en", "Options:\n"
					" -f,   --find     <regex pattern>    Pattern to search: Put in single cote '...'\n"
					"     or\n"
					" -s,   --scan     <volume to scan>   Path to volume/folder to scan.\n\n"
					" -ver, --version                     Program info version.\n"
					" -h,   --help                        Help message the exit.\n"
					"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"},
			{"fr", "Options:\n"
					" -f,   --find     <motif regex>        Motif à chercher: Mettre entre '...'\n"
					"     ou\n"
					" -s,   --scan     <volume à scanner>   Chemin du répertoire à scanner.\n\n"
					" -ver, --version                       Donne les info de version du programme.\n"
					" -h,   --help                          Montre ce message d'aide et termine.\n"
					"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"},
			{"es", "Opciones:\n"
					" -f,   --find     <patrón regex>         Patrón a buscar: Poner entre '...'\n"
					"   o \n"
					" -s,   --scan     <volumen a escanear>   Ruta del directorio a escanear.\n\n"
					" -ver, --version                         Proporciona información de la versión del programa.\n"
					" -h,   --help                            Muestra este mensaje de ayuda y finaliza.\n"
					"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"}}
			},
		{"message_erreur", {
			{"en", "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"
					"It's should be: archive <-f|--find pattern>\n"
					"                or\n"
					"                archive <-s|--scan volume to scan>\n"
					"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"},
			{"fr", "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"
					"Il faut faire: archive <-f|--find motif>\n"
					"               ou bien\n"
					"               archive <-s|--scan volume à scanner>\n"
					"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"},
			{"es", "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"
					"Se debe hacer: archive <-f|--find motif>\n"
					"               o\n"
					"               archive <-s|--scan volumen a escanear>\n"
					"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"}}
		}
	};

	#endif	// __STRINGS_SEL__
