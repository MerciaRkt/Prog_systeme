import os

for dossier in os.sys.argv[1:]:
    print(f"Répertoire" ,dossier ,"\n")

    for file in os.listdir(dossier):
        chemin = os.path.join(dossier, fichier)

        if os.path.isfile(chemin):
            taille = os.path.getsize(chemin)

            if size >= 1048576:  # 1 MB
                info = os.stat(chemin)
                print(f"{fichier} : UID = {info.st_uid}")