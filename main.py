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