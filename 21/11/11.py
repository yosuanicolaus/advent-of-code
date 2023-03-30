input = '''2344671212
6611742681
5575575573
3167848536
1353827311
4416463266
2624761615
1786561263
3622643215
4143284653'''


def main():
    octopus: list[list[int]] = []
    adjacents = [(-1, -1), (-1, 0), (-1, 1), (0, -1),
                 (0, 1), (1, -1), (1, 0), (1, 1)]
    flashes = 0
    visited = set()

    def dfs(r: int, c: int):
        nonlocal flashes
        if not (0 <= r < len(octopus) and 0 <= c < len(octopus[0])):
            return
        if (r, c) in visited:
            return

        octopus[r][c] += 1
        if octopus[r][c] >= 10:
            flashes += 1
            octopus[r][c] = 0
            visited.add((r, c))
            for ar, ac in adjacents:
                dfs(r + ar, c + ac)

    for line in input.split('\n'):
        octopus.append([])
        for dg in line:
            octopus[-1].append(int(dg))

    for _ in range(100):
        visited = set()

        for r in range(len(octopus)):
            for c in range(len(octopus[0])):
                dfs(r, c)

    print(flashes)


if __name__ == "__main__":
    main()
