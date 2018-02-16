from distutils.core import setup
from Cython.Build import cythonize

setup(
  name = 'Benchmark 1',
  ext_modules = cythonize("bm_initial_auth.pyx"),
)
