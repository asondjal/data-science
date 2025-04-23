import pandas as pd
import pandas.plotting as panda_plot
import matplotlib.pyplot as plt

document = pd.read_csv("./Aufgabe 1/College.csv")
print(document) # Auslesen der Daten 
print(document.describe()) # Deskriptive Statistik, z.B. Mittelwert, Minimum und Maximum

ten_frames = document.iloc[:, :10]
print(ten_frames)

data = panda_plot.scatter_matrix(ten_frames, figsize=(15,15), s=50, marker='D')
print(data)

# Boxplot für das Feature 'Outstate'
plt.figure(figsize=(8,6))  # Größe des Plots einstellen
plt.boxplot(data["Outstate"], vert=True, patch_artist=True)  # Boxplot zeichnen

# Achsentitel hinzufügen
plt.title("Boxplot des Features 'Outstate'")
plt.ylabel("Werte von Outstate")

# Plot anzeigen
plt.show(block = True)