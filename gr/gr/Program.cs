using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Program
{
    static void Main()
    {
        using (var reader = new StreamReader("input.txt"))
        using (var writer = new StreamWriter("output.txt"))
        {
            int n = int.Parse(reader.ReadLine());
            if (n == 1)
            {
                writer.WriteLine("NO");
                return;
            }

            List<List<int>> adjacencyList = new List<List<int>>(n);
            List<List<int>> transposedAdjacencyList = new List<List<int>>(n);

            for (int i = 0; i < n; i++)
            {
                adjacencyList.Add(new List<int>());
                transposedAdjacencyList.Add(new List<int>());
            }

            int tmp;
            for (int i = 0; i < n; i++)
            {
                var values = reader.ReadLine().Split().Select(int.Parse).ToArray();
                for (int j = 0; j < n; j++)
                {
                    tmp = values[j];
                    if (tmp == 0 && i != j)
                    {
                        adjacencyList[i].Add(j);
                        transposedAdjacencyList[j].Add(i);
                    }
                }
            }

            var result = FindStronglyConnectedComponents(adjacencyList, transposedAdjacencyList);
            var connectedComponents = SeparateComponents(result.Item2);

            var componentPartitions = new List<Tuple<List<int>, List<int>>>(result.Item1);

            for (int i = 0; i < result.Item1; i++)
            {
                var visited = new bool[n];
                var part = new bool[n];
                var partitionResult = PartitionComponent(connectedComponents[i][0], i, result.Item2, adjacencyList, visited, part);
                if (!partitionResult)
                {
                    writer.WriteLine("NO");
                    return;
                }

                for (int j = 0; j < part.Length; j++)
                {
                    if (result.Item2[j] == i)
                    {
                        if (part[j])
                            componentPartitions[i].Item1.Add(j);
                        else
                            componentPartitions[i].Item2.Add(j);
                    }
                }
            }

            componentPartitions.Sort((a, b) => Math.Max(a.Item1.Count, a.Item2.Count).CompareTo(Math.Max(b.Item1.Count, b.Item2.Count)));

            var teamA = new List<int>();
            var teamB = new List<int>();

            foreach (var cp in componentPartitions)
            {
                var p1 = cp.Item1.Where(x => result.Item2[x] == componentPartitions.IndexOf(cp)).ToList();
                var p2 = cp.Item2.Where(x => result.Item2[x] != componentPartitions.IndexOf(cp)).ToList();

                if (teamA.Count > teamB.Count)
                {
                    teamA.AddRange(p1);
                    teamB.AddRange(p2);
                }
                else
                {
                    teamA.AddRange(p2);
                    teamB.AddRange(p1);
                }
            }

            if (teamA.Count < teamB.Count)
            {
                Swap(ref teamA, ref teamB);
            }

            if (teamB.Count == 0)
            {
                writer.WriteLine("NO");
            }
            else if ((double)teamA.Count / teamB.Count > 2.0)
            {
                writer.WriteLine("NO");
            }
            else
            {
                writer.WriteLine("YES");
                writer.WriteLine(string.Join(" ", teamA.Select(x => x + 1)));
            }
        }
    }

    static void Swap<T>(ref T a, ref T b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

    static Tuple<int, List<int>> FindStronglyConnectedComponents(List<List<int>> adjacencyList, List<List<int>> transposedAdjacencyList)
    {
        int n = adjacencyList.Count;
        var visited = new bool[n];
        var ordered = new List<int>();
        for (int v = 0; v < n; v++)
        {
            if (!visited[v])
                Dfs1(v, adjacencyList, visited, ordered);
        }

        visited = new bool[n];
        int nComponents = 0;
        var component = new List<int>(n);
        foreach (var iv in ordered.Reverse<int>())
        {
            if (!visited[iv])
            {
                Dfs2(iv, transposedAdjacencyList, visited, component, nComponents);
                nComponents++;
            }
        }

        return Tuple.Create(nComponents, component);
    }

    static List<List<int>> SeparateComponents(List<int> vertexComponents)
    {
        int nComponents = vertexComponents.Max() + 1;
        var connectedComponents = new List<List<int>>(nComponents);
        for (int i = 0; i < nComponents; i++)
        {
            connectedComponents.Add(new List<int>());
        }

        for (int i = 0; i < vertexComponents.Count; i++)
        {
            connectedComponents[vertexComponents[i]].Add(i);
        }

        return connectedComponents;
    }

    static bool PartitionComponent(int v, int component, List<int> components, List<List<int>> adjacencyList, bool[] visited, bool[] part)
    {
        visited[v] = true;
        bool isBipartite = true;
        foreach (var u in adjacencyList[v])
        {
            if (components[u] == component)
            {
                if (visited[u] && part[u] == part[v])
                {
                    isBipartite = false;
                }

                if (!visited[u])
                {
                    part[u] = !part[v];
                    isBipartite = PartitionComponent(u, component, components, adjacencyList, visited, part);
                }
            }
        }

        return isBipartite;
    }

    static void Dfs1(int v, List<List<int>> adjacencyList, bool[] visited, List<int> ordered)
    {
        visited[v] = true;
        foreach (var u in adjacencyList[v])
        {
            if (!visited[u])
                Dfs1(u, adjacencyList, visited, ordered);
        }

        ordered.Add(v);
    }

    static void Dfs2(int v, List<List<int>> adjacencyListTransposition, bool[] visited, List<int> components, int nComponent)
    {
        visited[v] = true;
        components[v] = nComponent;
        foreach (var u in adjacencyListTransposition[v])
        {
            if (!visited[u])
            {
                Dfs2(u, adjacencyListTransposition, visited, components, nComponent);
            }
        }
    }
}
