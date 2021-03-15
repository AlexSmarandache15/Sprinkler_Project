import  math
cin = open("data_in.txt", "r")
cout = open("data_out.txt", "w")

def FoundPointX( y, radius ):   # valoarea pozitiva a lui x din ecuatia cercului
    return math.sqrt( math.fabs( radius * radius - y * y )  )

def ReadData( left, right, no_sprinklers, length, width  ): #functie pentru citirea datelor si formarea intervalelor de actiune pentru fiecare aspersor
    distance = 0
    radius = 0
    iterator = 0
    while iterator < no_sprinklers:
        distance = float(cin.readline())
        radius = float(cin.readline())
        if radius >= width: #pentru a acoperi complet o portiune de iarba, raza trebuie sa fie >= decat jumatate din latime
           x_point = FoundPointX(width,radius)
           # intervalul de acoperire completa al aspersorului va fi de forma: [distance - x_point, distance + x_point]
           # ne intereseaza doar intervalul complet acoperit din interiorul bandei de iarba, adica de la 0 la lungime
           round(x_point,5)
           left.append(float( distance - x_point ))
           if left[iterator] < 0:
               left[iterator] = 0
           right.append(float( distance + x_point ))
           if right[iterator] > length:
               right[iterator] = length
        else:
            left.append(float(0))
            right.append(float(0))
        iterator += 1
