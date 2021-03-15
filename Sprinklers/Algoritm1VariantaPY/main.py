#   Autor: Smarandache Alexandru
import read
import utils
import time
start_time = time.time()
left = [] #lista ce memoreaza capetele stangi ale intervalelor
right = [] #lista ce memoreaza capetele drepte ale intervalelor
available =[] #lista ce memoreaza disponibilitatea de testare a intervalelor
no_sprinklers = int(read.cin.readline())
length = float(read.cin.readline())
width = float(read.cin.readline())
width /= 2
read.ReadingData(left, right, no_sprinklers, length, width, available)
#apelam functia pentru citirea datelor si formarea intervalelor
read.cout.write(str(utils.MinimumNoSprinklers(no_sprinklers, left, right, available)) + "\n")
#afisam numarul minim de aspersoare care trebuie pornite
print("Timp executie program: --- %s seconds ---" % (time.time() - start_time) )
read.cin.close()
read.cout.close()
