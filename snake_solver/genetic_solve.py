from utils import Galaxy, Planet
import csv
from genetic import Gene
import random

POPULATION_SIZE = 2000
ELITISTS = int(0.05 * POPULATION_SIZE)
EPOCHS = 1000

if __name__ == "__main__":
    with open("galaxy.csv", "r") as f:
        reader = csv.reader(f)
        planets = [Planet(id, *row) for id, row in enumerate(reader)]

    galaxy = Galaxy(planets)
    population = [Gene(galaxy) for _ in range(POPULATION_SIZE)]
    
    scores = []    
     
    for epoch in range(EPOCHS):
        population.sort(key=lambda x: x.fitness)
        print(f"epoch {epoch}: score={population[0].fitness} solution={population[0].path()}")
        
        new_population = population[:ELITISTS]
        for _ in range(POPULATION_SIZE - ELITISTS):
            parent1, parent2 = random.choices(
                population=population,
                weights=[1 / g.fitness for g in population],
                k=2
            )
            new_population.append(parent1.reproduce(parent2))
        population = new_population
        