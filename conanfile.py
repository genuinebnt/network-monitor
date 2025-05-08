from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, CMakeDeps, cmake_layout

class ConanPackage(ConanFile):
    name = 'network-monitor'
    version = '0.1.0'
    settings = "os", "arch", "compiler", "build_type"
    default_options = {
        "boost/*:with_stacktrace_backtrace": False,
        "boost/*:without_locale": True
    }

    generators = 'CMakeDeps'

    def requirements(self):
        self.requires("boost/1.87.0")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
