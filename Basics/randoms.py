"""Simple Python-File using random library"""

from calendar import c
import random
random.seed()

def random_number(start: int, ende: int) -> int:
    """Generate a random number between 1 and 100."""
    return random.randint(start, ende)

def random_numbers(start: int, ende: int, size: int) -> list:
    """Generate a list of 10 random numbers between 1 and 100."""
    return random.sample(range(start, ende), size)

def generate_password(length: int) -> str:
    """Generate a random password of a given length."""
    characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()"
    return ''.join(random.choice(characters) for _ in range(length))

def guess_the_number() -> None:
    """Funktion, die ein Rate-Spiel simuliert"""
    print("Herzlich Willkommen im Spiel Guess-The-Number!")
    user_score = 0
    computer_score = 0
    while True:
        user_eingabe = int(input("Geben Sie eine Zahl im Bereich von 1 bis 10 ein: "))
        if user_eingabe < 1 or user_eingabe > 10:
            print("Bitte eine Zahl im Bereich von 1 bis 10 eingeben!")
            continue
        computer_eingabe = random.randint(1, 10)
        if user_eingabe == computer_eingabe:
            user_score += 1
            print("User: Ihre Eingabe war korrekt!")
        else:
            computer_score += 1
            if user_eingabe > computer_eingabe:
                print(f"User: Ihre Eingabe war um {user_eingabe - computer_eingabe} zu groß!")
            else:
                print(f"User: Ihre Eingabe war um {computer_eingabe - user_eingabe} zu klein!")
        print(f"Der Spielstand lautet: {user_score} : {computer_score}")
        if user_score - computer_score >= 3:
            print("Der User hat gewonnen!")
            break
        if computer_score - user_score >= 3:
            print("Der Computer hat gewonnen!")
            break

# print(random_number(1, 100))
# print(random_numbers(1, 100, 10))
# print(generate_password(12))
guess_the_number()
