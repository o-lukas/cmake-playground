    def package_info(self):
        # No information provided, only the in-package .cmake is used here
        # Other build systems or CMake via CMakeDeps will fail
        self.cpp_info.builddirs = ["lib/cmake"]
        self.cpp_info.set_property("cmake_find_mode", "none")
