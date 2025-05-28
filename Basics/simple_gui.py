"""Simple GUI using Tkinter"""
import tkinter as tk

# Hauptfenster erstellen
root = tk.Tk()
root.title("Mein Spiel")
root.geometry("500x500")  # Breite x Höhe

# Label hinzufügen
label = tk.Label(root, text="Willkommen!", font=("Helvetica", 16))
label.pack(pady=20)

# Eingabefeld
entry = tk.Entry(root)
entry.pack(pady=10)

# Button mit Aktion
def klicken():
    """Funktion, die beim Klicken des Buttons ausgeführt wird"""
    eingabe = entry.get()
    label.config(text=f"Du hast eingegeben: {eingabe}")

button = tk.Button(root, text="Absenden", command=klicken)
button.pack(pady=10)

# GUI starten
root.mainloop()
