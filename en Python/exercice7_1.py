import multiprocessing
import time
import os
def fils():
    while True:
        print("2+3=5")
        time.sleep(1)

p = multiprocessing.Process(target=fils)
p.start()
pid = p.pid 
while True:
    print("\nMENU\ns: stop\nr: reprendre\nq: quitter")
    choix = input("choix : ")
    if choix == "s": os.kill(pid, signal.SIGSTOP) 
    elif choix == "r": os.kill(pid, signal.SIGCONT)
    elif choix == "q":
        os.kill(pid, signal.SIGKILL)  
        break