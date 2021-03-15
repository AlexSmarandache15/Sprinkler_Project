import random
import math
def Insertion1 (iterator, sol_init, left, right ) :
    if sol_init != 1:
         position = random.randrange(0 , sol_init-1 )
    else:
         position = 0
    left.append( round( random.uniform( left[position], right[position] ), 4 ) )
    right.append( round( random.uniform( left[position], right[position] ), 4 ) )
    if ( left[iterator] > right[iterator] ):
        aux = left[iterator]
        left[iterator] = right[iterator]
        right[iterator] = aux

def Insertion2 (iterator, sol_init, left, right ):
    if sol_init == 1 or 2:
        position = 0
    else:
        position = random.randrange(0, sol_init - 2)
    left.append( round(random.uniform(left[position], (right[position] )), 4) )
    right.append( round(random.uniform( right[position], right[position+1] ), 4) )

maximum_splinkers = 10000

f = open('data_in.txt', 'w')
no_sprinklers = random.randrange( 1 , maximum_splinkers )
f.write(str( no_sprinklers ) + '\n')

if no_sprinklers > 1:
    sol_init = random.randrange(1, no_sprinklers )
else:
    sol_init = 1

left = []
right = []
left.append(0)
right.append( round( random.uniform(left[0], 100 ), 4) )

iterator = 1
while iterator != sol_init:
    left.append( round( random.uniform(left[iterator-1], right[iterator-1]  ), 4) )
    right.append( round( random.uniform(right[iterator-1], right[iterator-1] + 100 ), 4 ) )
    if right[iterator-1] == right[iterator] or left[iterator-1] == left[iterator]:
        --iterator
    iterator += 1

length = right[sol_init-1]
f.write(str(length)+'\n')
width = round( random.uniform(0, length), 4 )
f.write(str(width) + '\n')
iterator = sol_init
while  no_sprinklers > iterator:
    number1 = random.randrange(0,1)
    if  sol_init == 1 or  number1==1:
        Insertion1(iterator, sol_init, left, right)
    else:
        Insertion2(iterator, sol_init, left, right)
    iterator += 1

iterator = no_sprinklers
while iterator != 0 and no_sprinklers != 1:
    number1 = random.randrange(0, no_sprinklers-1)
    number2 = random.randrange(0, no_sprinklers-1)
    aux = left[number1]
    left[number1] = left[number2]
    left[number2] = aux
    aux = right[number1]
    right[number1] = right[number2]
    right[number2] = aux
    iterator -= 1

iterator = 0
width /= 2
while iterator < no_sprinklers:
    distance = round(((right[iterator] + left[iterator] ) / 2), 4)
    f.write(str(distance)+'\n')
    radius =  width * width + (right[iterator] - distance) * (right[iterator] - distance)
    radius = round (math.sqrt( radius ), 4) + 1
    f.write(str(radius)+'\n')
    iterator += 1

f.close()
