def SprinklersRequired( left, right, no_sprinklers, length ):
    sprinkler_count = 1   # variabila numara aspersoarele minime necesare
    iterator = 1
    covered = right[0]   # variabila marcheaza punctul pana unde a fost acoperita complet banda de iarba
    maximum = right[0]  # variabila folosita pentru a memora noul punct de acoperire completa a benzii de iarba
    while iterator < no_sprinklers and right[iterator] <= covered:
        iterator += 1
    while covered < length and iterator < no_sprinklers: #stabilim maximul dintre intervalele cu cel putin un punct in intervalul deja completat
        while iterator < no_sprinklers and left[iterator] <= covered:
            if right[iterator] > maximum:
                maximum = right[iterator]
            iterator += 1
        if covered != maximum:
            sprinkler_count += 1
        covered = maximum #actualizam capatul intervalului deja completat
    return sprinkler_count #returnam numarul minim de aspersoare care trebuie pornite

