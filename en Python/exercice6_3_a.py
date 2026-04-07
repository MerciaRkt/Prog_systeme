import struct

tab = []

for i in range(5):
    x = int(input(f"tab[{i}] = "))
    tab.append(x)
with open("tableau.bin", "wb") as f:
    f.write(struct.pack("5i", *tab))