#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#include "getFrancais.hpp"

bool searchPatternInFile(const std::string& filename, const std::string& pattern) {
	bool occurence = false;
	std::ifstream file(filename);

	if (!file.is_open()) {
		if (langFranc) std::cout << "Impossible d'ouvrir le fichier " << filename << std::endl;
		else std::cout << "Can't open file " << filename << std::endl;
		occurence = true;
		return occurence;
	}

	std::regex patternRegex(pattern, std::regex_constants::icase);
	std::string line;
	int lineNumber = 0;

	while (std::getline(file, line)) {
		lineNumber++;
		if (std::regex_search(line, patternRegex)) {
			std::cout << filename << " <=== " << line << std::endl;
			occurence = true;
		}
	}
	file.close();
	return occurence;
}

void findPattern(const std::string& pat) {
	std::string path = "/Users/danv/Documents/Archives/Volumes";  // Chemin du répertoire à parcourir
	
	// Changer le répertoire de travail
	if (chdir(path.c_str()) != 0) {
		if (langFranc) std::cerr << "Impossible de changer de répertoire vers " << path << std::endl;
		else std::cerr << "Can't chdir to path " << path << std::endl;
		return;
	}

	std::string tirets(pat.length(), '-');
	std::cout << tirets << "-------------------------------------------------------------" << std::endl;
	if (langFranc) std::cout << "Le motif «" << pat << "» dans " << path << "/*.txt" << std::endl;
	else std::cout << "Pattern  «" << pat << "»  in  " << path << "/*.txt" << std::endl;
	std::cout << tirets << "-------------------------------------------------------------" << std::endl;
//	listTxtFiles(".");

	DIR* dir = opendir(".");
	if (dir == nullptr) {
		if (langFranc) std::cerr << "Impossible d'ouvrir le répertoire " << path << std::endl;
		else std::cerr << "Can't open path " << path << std::endl;
		return;
	}

	struct dirent* entry;
	std::vector<std::string> dList;

	while ((entry = readdir(dir)) != nullptr) {
		std::string filename = entry->d_name;
		if (filename.length() > 4 && 
			filename.substr(filename.length() - 4) == ".txt") {
			dList.push_back(filename);
		}
	}
	closedir(dir);

	if (dList.size() > 0) {
		std::sort(dList.begin(), dList.end());
		for ( auto &f : dList ) {
			if (searchPatternInFile(f, pat)) std::cout << tirets
			<< "-------------------------------------------------------------" << std::endl;
		}
 	}
}
