
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
        const char* extension = ext.c_str();

        // File path string
        std::string path = y->path().string();

        // Replace the absolute data path with an empty string
        replace(path, data, "");

        // Get final cpk file
        const char* cpkFile = path.c_str();

        // If the file is a cpk
        if (strcmp(extension, ".cpk") != 0) {
            continue;
        }
        // To prevent loading the game's cpk we will check if it's in the ignoredCpks array.
        if (value_exists_in_array(cpkFile, ignoreCpks, IGNORE_CPKS_SIZE)) {
            continue;
        }

        // Replace the extension with an empty string
        replace(path, extension, "");

        // Mount cpk
        if (!MountCpk(cpkFile)) {
            printf("File: %s could not be loaded.\n", cpkFile);
        } else printf("%s was successfully loaded.\n", cpkFile);


    }
}