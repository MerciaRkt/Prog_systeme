import os

r1, w1 = os.pipe()  
r2, w2 = os.pipe()
pid = os.fork()
if pid == 0:
    mot = input("Entrez mot : ")
    os.write(w1, mot.encode())

    res = os.read(r2, 10).decode().strip()
    if res == "1": print("Le mot est dans le fichier")
    else: print("Le mot n est pas dans le fichier")
    os._exit(0)
else:
    mot = os.read(r1, 255).decode().strip()
    trouve = 0
    with open("fic.txt", "r") as f:
        for line in f:
            if mot in line.split():
                trouve = 1
                break
    os.write(w2, str(trouve).encode())
    os.wait()