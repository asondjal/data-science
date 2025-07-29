# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

import os
import sys
sys.path.insert(0, os.path.abspath('../python'))
extensions = ['sphinx.ext.autodoc']
HTMLT_THEME = 'sphinx_rtd_theme'

PROJECT = 'Data-Science'
COPYRIGHT = '2025, Arrif Sondjalim'
AUTHOR = 'Arrif Sondjalim'
RELEASE = '01.06.2025'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = []

templates_path = ['_templates']
exclude_patterns = []

LANGUAGE = 'Python'

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

HTMLT_THEME = 'alabaster'
html_static_path = ['_static']
