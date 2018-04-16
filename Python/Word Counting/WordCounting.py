testCases = int(input())
line = 1
while testCases + 1 != line:
    word = input().lower()
    sentence = input().lower()
    count = sentence.count(word)
    print("Line #" + str(line) + ": Word " + word + " occurred " + str(count) + " times")
    line += 1