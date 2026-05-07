a,b,c=map(eval,input().split(','))

S = 2 * (a*b + a*c + b*c)
V = a * b * c

print("面积为："+ str(S))
print(V)

