import os
p1_r, p1_w = os.pipe()
p2_r, p2_w = os.pipe()

pid = os.fork()
if pid == 0:
    os.close(p1_r)
    os.close(p2_w)
    mot = input("entrez un mot: ")
    os.write(p1_w, mot.encode())

    resultat = os.read(p2_r, 10).decode()
    if resultat == "1": print("Le mot est dans le fichier")
    else: print("Le mot n est pas dans le fichier")
    os._exit(0)
else:
    os.close(p1_w)
    os.close(p2_r)
    mot = os.read(p1_r, 255).decode().strip()
    trouve = 0
    with open("fic.txt", "r") as f:
        for line in f:
            if mot in line.split():
                trouve = 1
                break
    os.write(p2_w, str(trouve).encode())
    os.wait()