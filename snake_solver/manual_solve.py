import csv
import numpy as np
import itertools
from utils import Planet

FUEL = 550 
PATH = [
    [8, 28, 39],
    [19, 1, 21, 12, 32, 24, 35, 15, 4, 26],
    [17, 23, 14, 34, 6, 37],
    [10, 30, 3, 2, 27, 7],
    [18, 38, 22, 33, 13, 5],
    [16, 25],
    [36, 11, 31, 40, 20, 9, 29]
]
ALL = []
for p in PATH:
    ALL += p

with open("galaxy.csv", "r") as f:
    reader = csv.reader(f)
    planets = [Planet(id, *row) for id, row in enumerate(reader)]

galaxy = [[] for _ in range(6)]
for p in planets:
    #if p.id not in ALL:
    galaxy[p.priority].append(p)

for priority, planet_group in enumerate(galaxy):
    print(f"{len(planet_group)} planets")
    print(*planet_group, sep='\n')
    print("\n")
    
n = len(planets)

dists = np.zeros((n, n), dtype=np.int16)
for frm in range(n):
    for to in range(n):
        dists[frm][to] = planets[frm].dist(planets[to])

def min_loop_dist(path1, path2):
    path1 = [p.id for p in path1]
    path2 = [p.id for p in path2]
    best = None
    best_dist = np.inf
    for perm1 in itertools.permutations(path1):
        for perm2 in itertools.permutations(path2):
            dist = loop_dist(list(perm1) + list(perm2))
            if dist < best_dist:
                best_dist = dist
                best = list(perm1) + list(perm2)
    return best_dist, best

def loop_dist(path):
    # from & to Death Star
    path = [0] + path + [0]
    return path_dist(path)
    
def path_dist(path):
    dist = 0
    for i in range(len(path) - 1):
        dist += dists[path[i]][path[i+1]]
    return dist

# for priority in range(1, 6):
#     dist = path_dist([planets[0]] + galaxy[priority] + [planets[0]])
#     print(f"{priority}: {dist}")

# LAST
# for planet in galaxy[4]:
#     if planet.id == 11 or planet.id == 31 or planet.id == 5:
#         continue
#     print(planet.id, planet.name)
#     d, path = min_loop_dist(galaxy[5] + [planets[11], planets[31], planets[5]] + [planet])
#     print(d)
#     print([p.id for p in path])
#     print()

def score(path):
    return sum(map(loop_dist, path))

def format_path(path):
    res = ""
    for loop in path:
        res += planets[0].name +","
        res += ",".join(map(lambda x: planets[x].name, loop))
        res += ","
    res += planets[0].name
    return res
    
    
# for pref in itertools.combinations(galaxy[1], 0):
#     d, path = min_loop_dist([], galaxy[1])
#     if d <= FUEL:
#         print(d)
#         print([p.id for p in path])
#         print()
        
print(score(PATH))
print(len(ALL))
print(format_path(PATH))