import  math
cin = open("data_in.txt", "r")
cout = open("data_out.txt", "w")
def FoundPointX( y, radius ): #functie ce returneaza solutia pozitiva de pe axa Ox din ecuatia cercului
    return math.sqrt( math.fabs( radius * radius - y * y )  )

def ReadingData( left, right, no_sprinklers, length, width, available  ): #functie pentru citirea datelor si formarea intervalelor complet acoperite de fiecare aspersor
    distance = 0
    radius = 0
    iterator = 0
    while iterator < no_sprinklers:
        available.append(int(0))
        distance = float(cin.readline())
        radius = float(cin.readline())
        if radius >= width:
           x_point = FoundPointX(width,radius)
           round(x_point,5)
           left.append(float( distance - x_point )) #calculam capatul stang al intervalului
           if left[iterator] < 0: #ne intereseaza doar intervalul care este inclus in fasia de iarba, adica de la 0 la lungime
               left[iterator] = 0
           right.append(float( distance + x_point )) #calculam capatul drept al intervalului
           if right[iterator] > length:
               right[iterator] = length
        else:
            left.append(float(0))
            right.append(float(0))
            available[iterator] = 1 #daca punctul raza de actiune nu este cel putin egala cu jumatate din latime, nu acopera complet niciun punct
        iterator += 1

