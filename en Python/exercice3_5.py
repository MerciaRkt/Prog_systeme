import os
while True:
    fic = input("entrez un fichier : ")
    pid = os.fork()
    if pid == 0:
        os.execl("/usr/bin/emacs", "emacs", fic)
    os.wait()
    choix = input("Entrez Q pour quitter : ")
    if choix.lower() == 'q':
        break