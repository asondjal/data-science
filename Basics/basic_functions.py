"""Simple functions to demonstrate basic Python functionality."""

def count_words(txt: str) -> int:
    """
    Count the number of words in a string."""
    return len(txt.split())

print(count_words("Hello world!"))

def create_accronym(txt:str) -> str:
    """String to create an acronym from a string."""
    letters = list(txt)
    accronym = []
    for letter in letters:
        if letter.isupper():
            accronym.append(letter)
    return "".join(accronym)

print(create_accronym("Hello World!"))
