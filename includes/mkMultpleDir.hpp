#ifndef __MK_MULTIPLE_DIR__
	#define __MK_MULTIPLE_DIR__

	#include <iostream>
	#include <vector>
	#include <sys/stat.h>
	#include <string>
	#include <unistd.h> // Pour getcwd
	#ifdef __linux__
		#include <linux/limits.h>
	#else
		#include <limits.h> // Pour PATH_MAX
	#endif
	
	std::string getAbsolutePath(const std::string& relPath) {
		// Retourne toujours un path absolu de la string présentée
		std::string absPath = ""; 
		if (relPath[0] == '/') absPath = relPath;	// path = /.../.../...
		else {
			char cwd[PATH_MAX];
			if (getcwd(cwd, sizeof(cwd)) != nullptr) {
				if (relPath[0] == '.' && relPath[1] == '/') {	// path = ./.../.../...
					absPath = cwd + std::string("/") + relPath.substr(2);
				}
				else absPath = cwd + std::string("/") + relPath;	// path = .../.../...
			}
			else {
				std::cerr << "getcwd: Problème à récuprer le répertoire courrant." << std::endl;
				return ""; // Retourne une chaîne vide en cas d'erreur
			}
		}
		// Important de retourner un path avec / en final pour être sûr
		// que le dernier répertoire soit créé.
		if (absPath.back() != '/') return absPath + "/";
		return absPath;
	}
	
	bool dirExists(const std::string& path) {
		struct stat info;
		// Appelle la fonction stat sur le chemin fourni
		if (stat(path.c_str(), &info) != 0) return false; // Le chemin n'existe pas
		else if (info.st_mode & S_IFDIR) return true;  // C'est un répertoire
		return false; // Ce n'est pas un répertoire
	}
	
	bool createDir(const std::string& path) {
		// Important de fournir un path avec un / en final pour être sûr
		// que le dernier répertoire soit créé.
		std::vector<std::string> rep_a_creer = {};
		std::string parentPath = getAbsolutePath(path);
	
		if (parentPath == "") return false;
		std::cout << "Création de l'arborescence " << parentPath << std::endl;
	
		size_t pos = parentPath.find_last_of('/');
		while (true) {
			parentPath = parentPath.substr(0, pos);
			if (dirExists(parentPath)) break;
			else {
				rep_a_creer.insert(rep_a_creer.begin(), parentPath);
			}
				pos = parentPath.find_last_of('/');
		}
		for (const auto& nouveauRepertoire : rep_a_creer) {
			if (mkdir(nouveauRepertoire.c_str(), 0755) != 0) {
				std::cerr << "mkdir: Problème création du répertoire " << nouveauRepertoire << std::endl;
				return false;
			}
		}
		return true; // Répertoire(s) créé avec succès
	}

#endif //__MK_MULTIPLE_DIR__
