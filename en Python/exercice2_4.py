import os

pere = os.getpid()
fils1 = fils2 = fils3 = fils4 = fils5 = -1

for i in range(5):
    if i == 0: fils1 = os.fork()
    elif i == 1: fils2 = os.fork()
    elif i == 2: fils3 = os.fork()
    elif i == 3: fils4 = os.fork()
    elif i == 4: fils5 = os.fork()

    if os.getpid() != pere:
        break
if fils1 == 0:  print("Je suis le fils 1")
elif fils2 == 0: print("Je suis le fils 2")
elif fils3 == 0: print("Je suis le fils 3")
elif fils4 == 0: print("Je suis le fils 4")
elif fils5 == 0: print("Je suis le fils 5")