def DetermineCurrentBeginning ( left, right, start, end, available ): #functie pentru returnarea pozitiei intervalului cu cel mai mic capat stanga si cel mai mare capat dreapta
    iterator = start
    while iterator < end and available[iterator] != 0: #cautam primul interval disponibil
        iterator += 1
    position = iterator
    if position == end: #daca nu sunt intervale disponibile returnam -1
        return -1
    iterator += 1
    while iterator < end:
        if available[iterator] == 0:
            if ( (left[iterator] < left[position ] ) or ( ( left[position] == left[iterator] and right[position] < right[iterator]) ) ):
                position = iterator
        iterator += 1
    return position #returnam pozitia cautata

def MinimumNoSprinklers ( no_sprinklers, left, right, available ):
    no_necessary = 0 #variabila folosita pentru a numara intervalele absolut necesare
    position_of_first = DetermineCurrentBeginning(left, right, 0, no_sprinklers, available)
    #determinam pozitia primului interval
    while position_of_first != -1:
        available[position_of_first] += 1 #completam ca aspersorul a fost testat
        iterator = 0
        while iterator < no_sprinklers: #completam testarea intervalelor ce nu sunt necesare si actualizam capetele stangi ale celor care il au mai mic decat portiunea deja acoperita
            if available[iterator] == 0:
                if right[iterator] <= right[position_of_first]:
                    available[iterator] += 1
                elif left[iterator] < right[position_of_first]:
                    left[iterator] = right[position_of_first]
            iterator += 1
        no_necessary += 1
        position_of_first = DetermineCurrentBeginning( left, right, 0, no_sprinklers, available)
        #actualizam pozitia noului interval curent
    return no_necessary #returnam numarul minim de aspersoare necesare

