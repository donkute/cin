INF = 9999
n = int(input("Enter Number Of Nodes in Network: "))
cost = [[0 for _ in range(n)] for _ in range(n)]
distance = [[0 for _ in range(n)] for _ in range(n)]
next_hop = [[0 for _ in range(n)] for _ in range(n)]


print("Enter cost matrix(9999 for infinity): ")
for i in range(n):
    row = list(map(int, input().split()))
    for j in range(n):
        cost[i][j] = row[j]
        distance[i][j] = cost[i][j]
        if i==j or cost[i][j] == INF:
            next_hop[i][j]=-1
        else:
            next_hop[i][j] = j

updated = True
while updated:
    updated = False
    for i in range(n):
        for j in range(n):
            for k in range(n):
                if distance[i][k] + distance[k][j] < distance[i][j]:
                    distance[i][j] = distance[i][k] + distance[k][j]
                    next_hop[i][j] = next_hop[i][k]
                    updated = True

for i in range(n):
    print(f"\nElements of roounting table {i}\n")
    print("Destination\tNext Hop\t Cost\t")
    for j in range(n):
        if i == j:
            continue
        print(f"{j}\t\t",end=' ')
        
        if next_hop[i][j] == -1:
            print("N/A\t\t", end=' ')
        else:
            print(f"{next_hop[i][j]}\t\t", end=' ')
        print(distance[i][j])
