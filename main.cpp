
//
// Created by refactor on 10/8/18.
//


void main() {
    // Get all files in /data
    for (recursive_directory_iterator y(data), end; y != end; ++y) {
        // If path is not a directory
        if (is_directory(y->path())) {
            continue;
        }
        // Get file extension
        std::string ext = y->path().extension().string();

        // File path string
        std::string path = y->path().string();

        // Replace the absolute data path with an empty string
        replace(path, data, "");

        // If the file is a cpk
        if (strcmp(ext.c_str(), ".cpk") != 0) {
            continue;
        }
        // To prevent loading the game's cpk we will check if it's in the ignoredCpks array.
        if (value_exists_in_array(path.c_str(), ignoreCpks, IGNORE_CPKS_SIZE)) {
            continue;
        }

        // Replace the extension with an empty string
        replace(path, ext.c_str(), "");

        // Mount cpk
        if (!MountCpk(path.c_str())) {
            printf("File: %s could not be loaded.\n", path.c_str());
        } else printf("%s was successfully loaded.\n", path.c_str());


    }
}