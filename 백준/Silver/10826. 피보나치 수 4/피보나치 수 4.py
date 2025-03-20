a = 0;
b = 1;

num = int(input())

for i in range(num):
    temp = a;
    a = b
    b += temp

print(a)