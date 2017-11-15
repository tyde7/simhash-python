#!/usr/bin/env python

from distutils.core import setup, Extension 

MOD = 'csimhash'
setup(name = MOD, ext_modules=[Extension(MOD, sources = ['csimhash.cpp'])])