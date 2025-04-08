pocet = 0
susednosti = []
    
with open("input.txt") as file:
    index_line = 0
    for line in file:
        if index_line == 0:
            pocet = int(line.strip())
            index_line += 1
        else:
            susednost = list(line.strip())
            susedia = []
            for i in range(pocet):
                if susednost[i] == '1':
                    susedia.append(i)
            susednosti.append((index_line - 1, susedia))
            index_line += 1

    for i in susednosti:
        print(i)
    print("________________")

def isBipartite(graf):
    skupiny = [[],[]]
    aktualna_skupina = 0
    for i in graf:
        print(i)
        if i[0] not in skupiny[0] and i[0] not in skupiny[1]:  # pozrie ci je cislo ulozene aspon v jednej zo skupin, ak nie prida ho do skupiny[0]
            skupiny[0].append(i[0])
            aktualna_skupina = 0  #  znamena ze posledne ulozene cislo ktoreho susedov ideme kontrolovat je ulozene v skupiny[0]
        elif i[0] in skupiny[0]:
            aktualna_skupina = 0
        else:
            aktualna_skupina = 1

        for j in i[1]:  #  kontrola kazdeho suseda
            print(j, skupiny)
            if j in skupiny[aktualna_skupina]:   #   ak je sused v rovnakej skupine ako je kontrolovane cislo tak je graf nebipartny
                print("nie je bipartny")
                return False
            elif j not in (skupiny[(aktualna_skupina+1)%2]):   #  uzasna super duper zmena z 0 na 1 a opacne pomocou vzorca :D (ak nie je sused v druhej skupine tak ho tam prida)
                skupiny[(aktualna_skupina+1)%2].append(j)
    return True

    
isBipartite(susednosti)

