from utils import Galaxy, Planet
import csv

PATH = [[1, 21, 12, 24, 35, 15, 4, 32, 19], [39, 28, 8, 17], [26, 34, 14, 3, 30, 10], [37, 6, 23, 33, 13, 2, 38, 18], [22, 27, 7, 16], [31, 25, 5, 36], [11, 20, 40, 9, 29]]
if __name__ == "__main__":
    with open("galaxy.csv", "r") as f:
        reader = csv.reader(f)
        planets = [Planet(id, *row) for id, row in enumerate(reader)]
    galaxy = Galaxy(planets)
    print(galaxy.validate_path(PATH))
    print(galaxy.format_path(PATH))