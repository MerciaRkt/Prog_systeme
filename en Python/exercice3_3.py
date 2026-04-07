import os
fichier = input("entrez un nom de fichier : ")
os.execl("/usr/bin/emacs", "emacs", fichier)