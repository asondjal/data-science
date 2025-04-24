"""
Python comprehensions"""

import random

random.seed()

numbers = list(range(1, 11))
print(f"numbers:{numbers}")

symbols = list("abcdefghijklmnopqrstuvwxyz")
print(print(f"symbols:{symbols}"))

alphabet = {letter: index for index, letter in enumerate(symbols)}
print(f"alphabet:{alphabet}")

squares = [number**2 for number in numbers]
print(f"squares:{squares}")

random_numbers = [random.randint(1, 100) for _ in range(50)]
print(f"random_numbers: {random_numbers}")

duplicates = {
    random_number
    for random_number in random_numbers
    if random_numbers.count(random_number) > 1
}
print(f"duplicates: {duplicates}")

tuples = ((x,y) for x in range(1, 4) for y in range(1, 4))
print(f"tuples: {tuples}")
