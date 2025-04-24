"""Python file for calculator functions"""

class Calculator:
    """This is a simple Python script that contains four functions:
    add, subtract, multiply, and divide.
    """
    def __init__(self):
        pass

    def __repr__(self) -> str:
        return "Calculator"

    def add(self, a: float, b: float) -> float:
        """Add two numbers."""
        return a + b

    def subtrafct(self, a: float, b: float) -> float:
        """Subtract two numbers."""
        return a - b

    def multiply(self, a: float, b: float) -> float:
        """Multiply two numbers."""
        return a * b

    def divide(self, a: float, b: float) -> float:
        """Divide two numbers."""
        if b == 0:
            raise ValueError("Cannot divide by zero")
        return round(a / b, 2)

    def display(self) -> str:
        """Display the calculator."""
        eingabe = int(input("Geben Sie die Zahlen ein von 1 bis 4: "))
        if eingabe not in range(1, 5):
            raise ValueError("Bitte eine Zahl von 1 bis 4 eingeben")
        if eingabe == 1:
            print("Ihre ausgewaehlte Rechenoperation: Addition")
        elif eingabe == 2:
            print("Ihre ausgewaehlte Rechenoperation: Subtraktion")
        elif eingabe == 3:
            print("Ihre ausgewaehlte Rechenoperation: Multiplikation")
        elif eingabe == 4:
            print("Ihre ausgewaehlte Rechenoperation: Division")
        else:
            raise ValueError("Bitte eine Zahl von 1 bis 4 eingeben")
        a = float(input("Geben Sie die erste Zahl ein: "))
        print(f"Ihre erste Zahl lautet {a}")
        b = float(input("Geben Sie die zweite Zahl ein: "))
        print(f"Ihre zweite Zahl lautet {b}")
        zahl = 0
        if eingabe == 1:
            zahl = self.add(a, b)
        elif eingabe == 2:
            zahl = self.subtrafct(a, b)
        elif eingabe == 3:
            zahl = self.multiply(a, b)
        elif eingabe == 4:
            zahl = self.divide(a, b)
        return f"Ihr Ergebnis lautet {round(zahl, 2)}"

calculator = Calculator()
print(calculator.display())
