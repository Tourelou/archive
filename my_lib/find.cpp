#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#include "arc_locale.hpp"

bool searchPatternInFile(const std::string& filename, const std::string& pattern) {
	bool occurence = false;
	std::ifstream file(filename);

	if (!file.is_open()) {
		std::cout << arc_locale("err_open_file") << filename << std::endl;
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

void findPattern(const std::string& path,const std::string& pat) {
	
	// Changer le répertoire de travail
	if (chdir(path.c_str()) != 0) {
		std::cerr << arc_locale("err_cd_dir") << path << std::endl;
		return;
	}

	std::string tirets(pat.length(), '-');
	std::cout << tirets << "-------------------------------------------------------------" << std::endl;
	printf(arc_locale("info_find").c_str(), pat.c_str(), path.c_str());
	std::cout << tirets << "-------------------------------------------------------------" << std::endl;
//	listTxtFiles(".");

	DIR* dir = opendir(".");
	if (dir == nullptr) {
		std::cerr << arc_locale("err_open_dir") << path << std::endl;
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
