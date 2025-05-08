from conan import ConanFile
from conan.tools.cmake import CMakeToolchain

class ConanPackage(ConanFile):
    name = 'network-monitor'
    version = '0.1.0'
    settings = "os", "arch", "compiler", "build_type"

    generators = 'CMakeDeps'

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
