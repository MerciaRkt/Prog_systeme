import os
import sys

fd = int(sys.argv[1])
chaine = os.read(fd, 255).decode()
print("Message reçu :", chaine)