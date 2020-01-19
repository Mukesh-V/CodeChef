n = int(input())

a = [int(m) for m in input().split()]
b = [int(m) for m in input().split()]

l = [[]]
for i in range(n-1):
    l.append([])

for i in range(n-1):
    m,n = [int(m) for m in input().split()]
    l[m-1].append(n)

for i in range(n):
    for j in range( len(l[i]) ):
        l[i].extend(l[ l[i][j]-1 ])

r = 0
for i in range(n):
    r = r + min(a[i],b[i])
    for j in range( len(l[i]) ):
        r = r + min(max(a[i],a[ l[i][j]-1 ]),max(b[i],b[ l[i][j]-1 ]))

print(r)