#  Autor: Smarandache Alexandru
import sorting
import utils
import read
import time
start_time = time.time()
left = []
right = []
# listele left si right memoreaza intervalul de iarba complet acoperit de aspersor
# complet acoperit = portiunea verticala udata de aspersor sa fie mai mare decat cea a bandei de iarba
no_sprinklers = read.cin.readline()
no_sprinklers = int(no_sprinklers)
length = float(read.cin.readline())
width = float(read.cin.readline())
read.ReadData( left, right, no_sprinklers, length, width/2 )
sorting.QuickSort(left, right, 0, no_sprinklers - 1)
#sortam intervalele crescator dupa capatul din stanga și descrescator dupa cel din dreapta
read.cout.write(str(utils.SprinklersRequired(left, right, no_sprinklers, length )) + '\n') #afisam numarul minim de aspersoare ce trebuie pornite
print("Timp executie program: --- %s seconds ---" % (time.time() - start_time))
read.cin.close()
read.cout.close()
