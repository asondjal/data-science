from setuptools import Extension, setup

import pybind11

ext_modules = [
    Extension(
        "intersection",
        [
            "bindings/python_bindings.cpp",
            "src/main.cpp",
            "src/read_data.cpp",
            "src/logging.cpp",
            "src/statistik.cpp",
        ],
        include_dirs=[pybind11.get_include(), "inc"],
        language="c++",
        libraries=["poppler-cpp", "tinyxml2"],
        extra_compile_args=["-O3", "-std=c++17"],  # optional optimieren
    ),
]

setup(
    name="intersection",
    version="0.1.0",
    author="Arrif Sondjalim",
    description="Python-Bindings für Projekt Data-Science",
    ext_modules=ext_modules,
)
