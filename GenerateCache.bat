@echo off

SET install_folder=D:\INSTALL
IF %1==Debug GOTO Debug
IF %1==Release GOTO Release
GOTO End1

:Debug
SET build_folder=D:\BUILD\debug
rmdir /s /q %install_folder%
rmdir /s /q %build_folder%
mkdir %install_folder%
mkdir %build_folder%
conan install . design-patterns/1.0.0@test/stable -s build_type=Debug --install-folder %install_folder%
xcopy %install_folder%\conanbuildinfo.txt %build_folder%
xcopy %install_folder%\conanbuildinfo.cmake %build_folder%
conan build . --install-folder %install_folder% --build-folder %build_folder% --configure
GOTO End

:Release
SET build_folder=D:\BUILD\release
rmdir /s /q %install_folder%
rmdir /s /q %build_folder%
mkdir %install_folder%
mkdir %build_folder%
conan install . design-patterns/1.0.0@test/stable -s build_type=Debug --install-folder %install_folder%
xcopy %install_folder%\conanbuildinfo.txt %build_folder%
xcopy %install_folder%\conanbuildinfo.cmake %build_folder%
conan build . --install-folder %install_folder% --build-folder %build_folder% --configure
GOTO End

:End