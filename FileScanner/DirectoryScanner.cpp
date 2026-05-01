
#include <iostream>
#include <string>
#include <filesystem>
#include <windows.h>

using namespace std;


int main()
{
    SetConsoleOutputCP(CP_UTF8);

    string dirPathInString;
    int suspectFilesNumber = 0;

    cout << "=== Mini Scanner de dossier ===\n";

    cout << "\n";

    cout << "Veuillez entrer le chemin du dossier à scanner : ";                                               // écrire à l'utilisateur
    getline(cin, dirPathInString);
    
    filesystem::path dirPath = dirPathInString;

    cout << "\n";

    if (filesystem::exists(dirPath)) {                                                                             // check si le chemin du dossier existe
        if (filesystem::is_directory(dirPath)) {                                                                   // check si c'est bien un dossier
            cout << "Votre dossier a bien été trouvé, analyse du contenu du dossier en cours ..." << "\n";
            cout << "\n";
            for (const auto& entry : filesystem::directory_iterator(dirPath)) {                                     // boucler dans le dossier pour chercher tous les fichiers/dossiers dedans
                if (filesystem::is_regular_file(entry)) {
                    if (entry.path().extension() == ".exe" or entry.path().extension() == ".bat") {
                        cout << "Fichier suspect trouvé :" << entry.path().filename() << "\n";
                        suspectFilesNumber++;
                    }
                }
            }
            cout << "\n";
            cout << "L'analyse a détecté " << suspectFilesNumber << " fichiers suspects." << "\n";
        }
        else {
            cout << "Le chemin existe mais ce n'est pas un dossier." << "\n";
        }
    }
    else {
        cout << "Le chemin de votre dossier n'existe pas." << "\n";
    }

}
