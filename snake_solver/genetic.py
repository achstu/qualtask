import random
import itertools
from utils import Galaxy, N_PLANETS, FUEL
import copy

DEATH_STAR_PROB = 0.25
PERMUTATION_MUTATION_PROBABILITY = 0.2
DEATH_STAR_MUTATION_PROBABILITY = 0.2
 
# OX1 crossover
def ox1_crossover(gene1, gene2):
    gene_len = len(gene1)
    section_len = gene_len // 2
    section_start = random.randint(0, gene_len - section_len)
    section = gene1[section_start:section_start + section_len]
    other_unique = [g for g in gene2 if g not in section]
    return other_unique[:section_start] + section + other_unique[section_start:]

def binary_crossover(gene1, gene2):
    div = random.randint(0, len(gene1) - 1)
    return gene1[:div] + gene2[div:]

class Gene:
    def __init__(self, galaxy: Galaxy=None, permutations=None, death_stars=None):
        self.galaxy = galaxy
        
        if permutations is not None:
            self.permutations = permutations
        else:
            self.permutations = [[p.id for p in planets] for planets in galaxy.galaxy[1:]]
            for perm in self.permutations:
                random.shuffle(perm)
                
        if death_stars is not None:
            self.death_stars = death_stars
        else:
            self.death_stars = [random.random() < DEATH_STAR_PROB for _ in range(N_PLANETS - 1)] 
        
        self.fitness = self.calculate_fitness()
        
    def path(self):
        planets = itertools.chain.from_iterable(self.permutations)
        path = [[]]
        for i, planet in enumerate(planets):
            path[-1].append(planet)
            if i < N_PLANETS - 1 and self.death_stars[i]:
                path.append([])
        return path
        
    def calculate_fitness(self):
        score = 0
        for loop in self.path():
            loop_score = self.galaxy.loop_dist(loop)
            score += loop_score
            if loop_score > FUEL:
                score += loop_score * loop_score
        return score
    
    def permutation_crossover(self, other):
       return [ox1_crossover(g1, g2) for g1, g2 in zip(self.permutations, other.permutations)]
        
    def reproduce(self, other):
        # determines type of crossover
        r = random.random()
        
        # death star crossover
        if r < 0.75:
            death_stars = binary_crossover(self.death_stars, other.death_stars)
        elif random.random() < 0.5:
            death_stars = copy.deepcopy(self.death_stars)
        else:
            death_stars = copy.deepcopy(other.death_stars)
            
        # permutation crossover
        if r > 0.25:
            permutations = self.permutation_crossover(other)
        elif random.random() < 0.5:
            permutations = copy.deepcopy(self.permutations)
        else:
            permutations = copy.deepcopy(other.permutations)
            
        # death star mutation
        if random.random() < DEATH_STAR_MUTATION_PROBABILITY:
            i = random.randint(0, len(death_stars) - 1)
            death_stars[i] = not death_stars[i]
        
        # permutation mutation
        if random.random() < PERMUTATION_MUTATION_PROBABILITY:
            permutation = random.choices(permutations, weights=[len(p) for p in permutations], k=1)[0]
            i, j = random.sample(range(len(permutation)), 2)
            permutation[i], permutation[j] = permutation[j], permutation[i]
        
        return Gene(galaxy=self.galaxy, permutations=permutations, death_stars=death_stars)
            