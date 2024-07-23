def dfs1(v, adjacency_list, visited, ordered):
    visited[v] = True
    for u in adjacency_list[v]:
        if not visited[u]:
            dfs1(u, adjacency_list, visited, ordered)
    ordered.append(v)


def dfs2(v, adjacency_list_transposition, visited, components, n_component):
    visited[v] = True
    components[v] = n_component
    for u in adjacency_list_transposition[v]:
        if not visited[u]:
            dfs2(u, adjacency_list_transposition, visited, components, n_component)


def componentspPartition(adjacency_list, transposed_adjacency_list):
    n = len(adjacency_list)
    visited = [False] * n
    ordered = []

    for v in range(n):
        if not visited[v]:
            dfs1(v, adjacency_list, visited, ordered)

    visited = [False] * n
    n_components = 0
    component = [0] * n

    for iv in reversed(ordered):
        if not visited[iv]:
            dfs2(iv, transposed_adjacency_list, visited, component, n_components)
            n_components += 1

    return n_components, component


def components(n_components, vertex_components):
    connected_components = [[] for _ in range(n_components)]
    for i, component in enumerate(vertex_components):
        connected_components[component].append(i)
    return connected_components


def bipatite_component(v, component, components, adjacency_list, visited, part):
    visited[v] = True
    is_bipartite = True

    for u in adjacency_list[v]:
        if components[u] == component:
            if visited[u] and part[u] == part[v]:
                is_bipartite = False
            if not visited[u]:
                part[u] = not part[v]
                is_bipartite = bipatite_component(u, component, components, adjacency_list, visited, part)

    return is_bipartite


if __name__ == "__main__":
    with open("input.txt", "r") as infile, open("output.txt", "w") as outfile:
        n = int(infile.readline().strip())
        if n == 1:
            outfile.write("NO\n")
            exit()

        graph = [[] for _ in range(n)]
        transposed_adjacency_list = [[] for _ in range(n)]

        for i in range(n):
            row = list(map(int, infile.readline().split()))
            for j in range(n):
                if row[j] == 0 and i != j:
                    graph[i].append(j)
                    transposed_adjacency_list[j].append(i)

        n_components, vertex_components = componentspPartition(graph, transposed_adjacency_list)
        connected_components = components(n_components, vertex_components)
        comps = [([], []) for _ in range(n_components)]

        for i in range(n_components):
            visited = [False] * n
            part = [False] * n
            res = bipatite_component(connected_components[i][0], i, vertex_components, graph, visited, part)

            if not res:
                outfile.write("NO\n")
                exit()

            for j in range(len(part)):
                if vertex_components[j] == i:
                    if part[j]:
                        comps[i][0].append(j)
                    else:
                        comps[i][1].append(j)
            visited = [False] * n

        comps.sort(key=lambda cp: max(len(cp[0]), len(cp[1])), reverse=True)

        firstTeam = []
        secondTeam = []

        for cp in comps:
            p1, p2 = cp
            if len(firstTeam) > len(secondTeam):
                if len(p1) > len(p2):
                    firstTeam.extend(p2)
                    secondTeam.extend(p1)
                else:
                    firstTeam.extend(p1)
                    secondTeam.extend(p2)
            else:
                if len(p1) > len(p2):
                    firstTeam.extend(p1)
                    secondTeam.extend(p2)
                else:
                    firstTeam.extend(p2)
                    secondTeam.extend(p1)

        if len(firstTeam) < len(secondTeam):
            firstTeam, secondTeam = secondTeam, firstTeam

        if len(firstTeam) / len(secondTeam) > 2.0:
            outfile.write("NO\n")
        else:
            firstTeam.sort()
            outfile.write("YES\n")
            outfile.write(" ".join(map(lambda x: str(x + 1), firstTeam)))
