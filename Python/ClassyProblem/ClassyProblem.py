names = {}
maxClassLength = 0


testCases = int(input())
while testCases > 0:
    numNames = int(input())
    while numNames > 0:
        line = input()
        line = line.split()
        name = line[0][:-1]
        classes = line[1].split('-')
        names[name] = 0

        for clazz in classes:
            if clazz == "upper":
                names[name] += 1
            elif clazz == "lower":
                names[name] -= 1
        numNames -= 1

    for item in sorted(names.items(), key=lambda x: (-x[1], x[0])):
        print(item[0])

    testCases -= 1
    names.clear()
    print("==============================")
