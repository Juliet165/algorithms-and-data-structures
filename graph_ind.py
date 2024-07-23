def solve(n, matrix):
    # Создаем список смежности
    adj_list = [[] for _ in range(n)]
    for i in range(n):
        for j in range(i + 1, n):
            if matrix[i][j] == 1:
                adj_list[i].append(j)
                adj_list[j].append(i)

    # Инициализируем массив цветов (-1 - не покрашена, 0 - первая команда, 1 - вторая команда)
    color = [-1] * n

    # Функция проверки раскраски графа
    def is_bipartite_dfs(v, c):
        nonlocal color
        color[v] = c
        for u in adj_list[v]:
            if color[u] == -1:
                if not is_bipartite_dfs(u, 1 - c):
                    return False
            elif color[u] == c:
                return False
        return True

    # Проверка двудольности для каждой компоненты связности
    for i in range(n):
        if color[i] == -1:
            if not is_bipartite_dfs(i, 0):
                return "NO"

    # Разбиваем вершины на команды
    team1 = [i + 1 for i in range(n) if color[i] == 0]
    team2 = [i + 1 for i in range(n) if color[i] == 1]

    # Проверка численности
    if abs(len(team1) - len(team2)) <= 2:
        return "YES\n" + " ".join(map(str, team1)) if len(team1) > len(team2) else "YES\n" + " ".join(map(str, team2))
    else:
        return "NO"

# Чтение входных данных
n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]

# Решение задачи и вывод результатов
result = solve(n, matrix)
print(result)
