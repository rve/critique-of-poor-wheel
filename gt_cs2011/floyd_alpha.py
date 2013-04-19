def adj(g):
    """
    Convert a directed graph to an adjaceny matrix.
    >>> g = {1: {2: 3, 3: 8, 5: -4}, 2: {4: 1, 5: 7}, 3: {2: 4}, 4: {1: 2, 3: -5}, 5: {4: 6}}
    >>> adj(g)
    {1: {1: 0, 2: 3, 3: 8, 4: inf, 5: -4}, 2: {1: inf, 2: 0, 3: inf, 4: 1, 5: 7}, 3: {1: inf, 2: 4, 3: 0, 4: inf, 5: inf}, 4: {1: 2, 2: inf, 3: -5, 4: 0, 5: inf}, 5: {1: inf, 2: inf, 3: inf, 4: 6, 5: 0}}
    """
    vertices = g.keys()
 
    dist = {}
    for i in vertices:
        dist[i] = {}
        for j in vertices:
            try:
                dist[i][j] = g[i][j]
            except KeyError:
                # the distance from a node to itself is 0
                if i == j:
                    dist[i][j] = 0
                # the distance from a node to an unconnected node is infinity
                else:p
                    dist[i][j] = float('inf')
    return dist
 
 
def fw(g):
    """
    Run the Floyd Warshall algorithm on an adjacency matrix.
 
    The Floyd Warshall algorithm computes the minimum cost of a simple path between each
    pair of vertices.
    >>> g = {1: {2: 3, 3: 8, 5: -4}, 2: {4: 1, 5: 7}, 3: {2: 4}, 4: {1: 2, 3: -5}, 5: {4: 6}}
    >>> fw(adj(g))
    {1: {1: 0, 2: 1, 3: -3, 4: 2, 5: -4}, 2: {1: 3, 2: 0, 3: -4, 4: 1, 5: -1}, 3: {1: 7, 2: 4, 3: 0, 4: 5, 5: 3}, 4: {1: 2, 2: -1, 3: -5, 4: 0, 5: -2}, 5: {1: 8, 2: 5, 3: 1, 4: 6, 5: 0}}
    >>> h = {1: {2: 1}, 2: {1 : 1, 3: -1}, 3: {2: -1}}
    >>> fw(adj(h))
    {1: {1: 0, 2: -1, 3: -2}, 2: {1: -1, 2: -2, 3: -3}, 3: {1: -2, 2: -3, 3: -4}}
    """
    vertices = g.keys()
    path = dict()
    for i in vertices:
        for j in vertices:
            path[i][j] = -1

    d = dict(g)  # copy g
    for k in vertices:
        for i in vertices:
            for j in vertices:
                if d[i][k] + d[k][j] < d[i][j]:
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j])
                    path[i][j] = path[i][k]
    return (d, path)
 
 
if __name__ == "__main__":
    #g = {1: {2: 3, 3: 5}, 2: {3: 6, 4: 3, 5: 10}, 3: {4: 4, 6: 9}, 4 : {3: 3, 6: 3, 5: 6}, 5: {4: 4, 6: 3, 7: 2}, 6: {7: 2}, 7: {}}
    g = {1: {2: 3, 3: 5}, 2: {4: 7}, 3: {4: 1}, 4: {}}
    (d, path) = fw(adj(g))
    print d
