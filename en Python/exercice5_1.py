import threading

def fonction(tab):
    for i in range(3):
        print(tab[i])

tab = [1, 2, 3]
thread = threading.Thread(target=fonction, args=(tab,))
thread.start()
thread.join()