from heapq import heapify, heappop, heappush
def prim_std(G):
    """Input: A connected undirected graph G=(V, E) with edge weights
Output: A minimum spanning tree defined by the dict prev
This prim uses heapq in standard library, with 3 times faster than prim(G).
    """
    V, E = G
    cost = {}
    prev = {}
    for u in V:
        cost[u] = float("inf")
        prev[u] = None
    cost[V[0]] = 0
    H = [(cost[u], u) for u in V]
    heapify(H)
    while len(H):
        costv, v = heappop(H)
        for z in E[v]:
            weightVZ = E[v][z]
            if cost[z] > weightVZ:
                try:
                    indexZ = H.index((cost[z], z))
                except ValueError:
                    continue
                cost[z] = weightVZ
                prev[z] = v
                print  "From <%d> to <%d> cost: %d" % (v,z,weightVZ)
                H[indexZ] = (cost[z], z)
                heapify(H)
    return prev

if __name__ == '__main__':
    V = a, b, c, d, e, f = range(6)
    E = {
        a: {b:5, c:6, d:4},
        b: {a:5, c:1, d:2},
        c: {a:6, b:1, d:2, e:5, f:3},
        d: {a:4, b:2, c:2, f:4},
        e: {c:5, f:4},
        f: {c:3, d:4, e:4}
        }
    G = (V, E)
    print prim_std(G)
    V = a,b = range(2)
    E = {
        a: {b: 3},
        b: {a:1}
        }
    G = (V, E)
    print prim_std(G)
