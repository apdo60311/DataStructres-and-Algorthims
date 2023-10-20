import math

money = int(input())
denom = [1, 3, 4]
min = [0] + [math.inf]*money
# print(min)

for i in range(1, money+1):
    for j in denom:
        if i>=j:
            coins = min[i-j]+1
            if coins < min[i]:
                min[i] = coins

print(min[money])

