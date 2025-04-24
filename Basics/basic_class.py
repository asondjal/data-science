"""
Simple Python class"""

class Produkt:
    """This is a simple Python script that contains two functions:"""

    def __init__(self, name: str, preis: float, anzahl: float):
        self.name = name
        self.preis = preis
        self.anzahl = anzahl

    def __repr__(self) -> str:
        return "Produkt"

    def get_name(self) -> str:
        """Get the name of the product."""
        return self.name

    def get_preis(self) -> float:
        """Get the price of the product."""
        return self.preis

    def get_anzahl(self) -> float:
        """Get the amount of the product."""
        return self.anzahl

    def show_info(self) -> str:
        """Show the information of the product."""
        return f"Produkt: {self.name}, Preis: {self.preis}, Anzahl: {self.anzahl}"

produkt = Produkt("Apfel", 1.5, 10)
print(produkt.show_info())
print(produkt.get_name())
print(produkt.get_preis())
print(produkt.get_anzahl())
print(produkt)
