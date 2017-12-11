#!/usr/bin/env python
# -*- coding: utf-8 -*-

from conans import ConanFile

class LhparsonConan(ConanFile):
    name = "lh-parson"
    version = "0.1.0"
    description = "Library to wrap the parson json library with libhandler"
    generators = "cmake"
    url = "https://github.com/solvingj/lh-parson"
    requires = "libhandler/0.5@bincrafters/stable", \
                "Parson/0.1.0@bincrafters/stable"




