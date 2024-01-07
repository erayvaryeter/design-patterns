from conans import ConanFile, CMake, tools

class DesignPatternsConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake_multi", "txt", "cmake"
    
    name = "design-patterns"
    version = "1.0.0"
    license = "proprietary"
    description = "tools"
    no_copy_source = True
    exports_sources = [ "*" ]

    def imports(self):
       self.copy("*.dll")
    
    def requirements(self):
        self.requires("cxxopts/[>=3.1.1]@")
        self.requires("catch2/[=3.5.1]@")

    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.configure()
        return cmake
        
    def build(self):
        cmake = self._configure_cmake()
        cmake.build()
        
    def package(self):
        cmake = self._configure_cmake()
        cmake.install()
        
    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)