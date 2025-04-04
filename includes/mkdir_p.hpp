#ifndef __MKDIR_P__
	#define __MKDIR_P__

	#include <string>
	#include <sys/stat.h>
	#include <errno.h>

	bool dirExists(const std::string& path) {
		struct stat info;
		// Appelle la fonction stat sur le chemin fourni
		if (stat(path.c_str(), &info) != 0) return false; // Le chemin n'existe pas
		else if (info.st_mode & S_IFDIR) return true;  // C'est un répertoire
		return false; // Ce n'est pas un répertoire
	}

	// Creates directories recursively like "mkdir -p".
	// Returns true on success, false on failure.
	bool createDir(const std::string &path) {
		if (path.empty()) return false;

		size_t pos = 0;
		std::string currentPath;

		// Handle absolute Unix-style paths.
		if (path[0] == '/') {
			pos = 1;
			currentPath = "/";
		}

		while (pos < path.size()) {
			size_t next = path.find_first_of('/', pos);
			if (next == std::string::npos) {
				currentPath.append(path, pos, path.size() - pos);
				pos = path.size();
			}
			else {
				currentPath.append(path, pos, next - pos);
				pos = next + 1;
			}
			// Skip if currentPath is empty (which may happen with multiple separators)
			if (currentPath.empty())
				continue;

			// Try to create the directory.
			if (mkdir(currentPath.c_str(), 0755) != 0) {
				// If directory already exists, ignore error.
				if (errno != EEXIST)
					return false;
			}
			// Append a separator if not at end and currentPath doesn't end with one.
			if (pos < path.size() && currentPath.back() != '/')
				currentPath.push_back('/');
		}
		return true;
	}

#endif	// __MKDIR_P__