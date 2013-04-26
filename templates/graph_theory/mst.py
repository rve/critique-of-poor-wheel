from heapq import heapify, heappop, heappush

parent = dict()
rank = dict()

def make_set(vertice):
    parent[vertice] = vertice
    rank[vertice] = 0

def find(vertice):
    if parent[vertice] != vertice:
        parent[vertice] = find(parent[vertice])
    return parent[vertice]

def union(vertice1, vertice2):
    root1 = find(vertice1)
    root2 = find(vertice2)
    if root1 != root2:
        if rank[root1] > rank[root2]:
            parent[root2] = root1
        else:
            parent[root1] = root2
            if rank[root1] == rank[root2]: rank[root2] += 1

def kruskal(G):
    for vertice in graph['vertices']:
        make_set(vertice)

    minimum_spanning_tree = set()
    edges = list(graph['edges'])
    edges.sort()
    for edge in edges:
        weight, vertice1, vertice2 = edge
        if find(vertice1) != find(vertice2):
            union(vertice1, vertice2)
            minimum_spanning_tree.add(edge)
    return minimum_spanning_tree

graph = {
        'vertices': ['A', 'B', 'C', 'D', 'E', 'F'],
        'edges': set([
            (1, 'A', 'B'),
            (5, 'A', 'C'),
            (3, 'A', 'D'),
            (4, 'B', 'C'),
            (2, 'B', 'D'),
            (1, 'C', 'D'),
            ])
        }
minimum_spanning_tree = set([
            (1, 'A', 'B'),
            (2, 'B', 'D'),
            (1, 'C', 'D'),
            ])
assert kruskal(graph) == minimum_spanning_tree
def prim_std(G):
	"""Input: A connected undirected graph G=(V, E) with edge weights
Output: A minimum spanning tree defined by the dict prev
This prim uses heapq in standard library 
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
	print kruskal(graph)
