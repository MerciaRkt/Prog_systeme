import os
import sys

while True:
    rep = input("entrez un repertoire : ")
    pid = os.fork()
    if pid == 0: 
        os.execl("/bin/cp", "cp", "-r", ".", rep)
    os.wait()
    choix = input("Entrez Q pour quitter : ")
    if choix.lower() == 'q':
        break