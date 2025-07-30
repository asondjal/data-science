# Data-Science

## Ziele

- Mathe-Kenntnisse: Umgang mit Matrixoperationen verbessern, Fokus liegt auf der linearen Algebra sowie Numerik
- Dataflow: Datensätze beschreiben sowie interpretieren
- Klasse ReadData: Einführung der Dateiformate HTML sowie XML und Anpassung der Datenspeicherung

## Erzeugung vom Coverage-Report

1. CMakeLists.txt anpassen: set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 --coverage") als Flag setzen
2. Projekt kompilieren
3. Große Coverage anlegen: lcov --capture      --directory build/CMakeFiles/cpp_tests.dir      --output-file temp.info      --ignore-errors unused,empty
4. Kleine Coverage basierend der kleinen Coverage, da sonst nicht anders möglich: lcov --capture      --directory build/CMakeFiles/cpp_tests.dir      --output-file temp.info      --ignore-errors unused,empty
5. Generieren von Reports zur Coverage in Format HTML, siehe Ordner covarage-report
