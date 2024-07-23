def print_matrix(matrix):
    for row in matrix:
        print(" ".join(map(str, row)))


def search(n, m, matrix, route, direction):
    npos = (direction // 10 + route[-1][0], direction % 10 + route[-1][1])
    
    if (
        npos[0] < 0
        or npos[0] >= n
        or npos[1] < 0
        or npos[1] >= m
        or matrix[npos[0]][npos[1]] != 0
    ):
        return False
    else:
        route.append(npos)
        matrix[npos[0]][npos[1]] = 1

        if npos[0] == n - 1:
            return True
        else:
            priority_dirs = []

            if direction == down:
                priority_dirs = [left, down, right]
            elif direction == left:
                priority_dirs = [left, down, up]
            elif direction == right:
                priority_dirs = [down, right, up]
            elif direction == up:
                priority_dirs = [left, right, up]

            found = False

            for i in range(3):
                found = search(n, m, matrix, route, priority_dirs[i])
                if found:
                    return True

            matrix[npos[0]][npos[1]] = 0
            route.pop()
            return False


def find_route(n, m, matrix, begin):
    route = [(0, begin)]
    if n != 1 and not search(n, m, matrix, route, down):
        raise Exception
    return route


if __name__ == "__main__":
    with open("input.txt", "r") as file:
        n, m, k = map(int, file.readline().split())
        x = list(map(int, file.readline().split()))
        y = list(map(int, file.readline().split()))

        matrix = [list(map(int, file.readline().split())) for _ in range(n)]

    possible = True
    symbol = 1
    max_people = 0
    max_people_matrix = []

    for i in range(k):
        if matrix[0][x[i] - 1] == 0:
            symbol += 1
            try:
                route = find_route(n, m, matrix, x[i])

                if len(route) > max_people:
                    max_people = len(route)
                    max_people_matrix = [[0] * m for _ in range(n)]
                    for r in route:
                        max_people_matrix[r[0]][r[1]] = symbol

            except Exception:
                possible = False
                break

    with open("output.txt", "w") as output_file:
        #output_file.write("YES" if possible else "NO" + "\n")
        output_file.write(str(max_people) + "\n")
        print_matrix(max_people_matrix)
