import numpy as np
import itertools

FUEL = 550 
MAX_PRIORITY = 5
N_PLANETS = 40

class Planet:
    def __init__(self, id, name, x, y, z, priority):
        self.id = id
        self.name = name
        self.x = int(x)
        self.y = int(y)
        self.z = int(z)
        self.priority = int(priority)
    
    def __repr__(self):
        return f"{self.id}: {self.name} ({self.x}, {self.y}, {self.z}) priotity: {self.priority}"
    
    def dist(self, other):
        return abs(self.x - other.x) + abs(self.y - other.y) + abs(self.z - other.z)
    
    def cords(self):
        return self.x, self.y, self.z
    
class Galaxy:
    def __init__(self, planets):
        self.planets = planets
        self.galaxy = [[] for _ in range(MAX_PRIORITY + 1)]
        for p in planets:
            self.galaxy[p.priority].append(p)
            
        self.n = len(planets)    
        
        self.dists = np.zeros((self.n, self.n), dtype=np.int64)
        for frm in range(self.n):
            for to in range(self.n):
                self.dists[frm][to] = planets[frm].dist(planets[to])
                
    def min_loop_dist(self, path1, path2):
        path1 = [p.id for p in path1]
        path2 = [p.id for p in path2]
        best = None
        best_dist = np.inf
        for perm1 in itertools.permutations(path1):
            for perm2 in itertools.permutations(path2):
                dist = self.loop_dist(list(perm1) + list(perm2))
                if dist < best_dist:
                    best_dist = dist
                    best = list(perm1) + list(perm2)
        return best_dist, best

    def loop_dist(self, path):
        # from & to Death Star
        path = [0] + path + [0]
        return self.path_dist(path)
        
    def path_dist(self, path):
        dist = 0
        for i in range(len(path) - 1):
            dist += self.dists[path[i]][path[i+1]]
        return int(dist)
    
    def score(self, path):
        return sum(map(self.loop_dist, path))
    
    def format_path(self, path):
        res = ""
        for loop in path:
            res += self.planets[0].name +","
            res += ",".join(map(lambda x: self.planets[x].name, loop))
            res += ","
        res += self.planets[0].name
        return res
    
    def validate_path(self, path):
        max_priority = 0
        planet_count = 0
        for loop in path:
            for planet in loop:
                planet_count += 1
                if self.planets[planet].priority < max_priority:
                    return False
                max_priority = max(max_priority, self.planets[planet].priority)
            dist = self.loop_dist(loop)
            if dist > FUEL:
                return False
        if planet_count != N_PLANETS:
            return False
        return True
