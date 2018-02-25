names = {}
maxClassLength = 0


def checkClass(namesList):
    output = {}
    for n in namesList:
        for name, classes in n.items():

            output[name] = 0
            classes = list(reversed(classes))
            while len(classes) < maxClassLength:
                classes.append("middle")

            for clazz in classes:
                if clazz == "upper":
                    output[name] += 3
                elif clazz == "middle":
                    output[name] += 2
                else:
                    output[name] += 1
                output[name] *= 10

    for item in sorted(output.items(), key=lambda x: (-x[1], x[0])):
        print(item[0])


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
    checkClass(names)
    names.clear()
    print("==============================")
