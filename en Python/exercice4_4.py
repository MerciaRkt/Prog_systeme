import os

tube_lecture, tube_ecriture = os.pipe()

pid = os.fork()
if pid == 0:
    os.close(tube_ecriture)
    os.environ["TUBE"] = str(tube_lecture)
    os.execlp("python3", "python3", "fils1.py")

else:
    os.close(tube_lecture)
    os.write(tube_ecriture, b"Bonjour")