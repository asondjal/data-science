#!/bin/bash

set -e  # Script beendet sich bei Fehlern

# Coverage-Ordner vorbereiten
REPORT_DIR="c++_coverage"
mkdir -p "$REPORT_DIR"

echo "📈 Erzeuge Coverage-Report..."
gcovr -r . \
  --filter='cpp_tests/' \
  --exclude='src/' \
  --exclude='pybind11/' \
  --exclude='bindings/' \
  --exclude='external/' \
  --html-details "$REPORT_DIR/index.html" \
  --txt "$REPORT_DIR/summary.txt"

echo "✅ Coverage-Reports erstellt:"
echo "   - HTML: $REPORT_DIR/index.html"
echo "   - Text: $REPORT_DIR/summary.txt"
