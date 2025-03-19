s = input()

a = ord("a")
for i in range(26):
    print(s.find(chr(a + i)), end=" ")