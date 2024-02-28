@echo off

SET install_folder=D:\INSTALL
set build_type=%1
SET build_folder=%2

rmdir /s /q %install_folder%
rmdir /s /q %build_folder%
mkdir %install_folder%
mkdir %build_folder%
mkdir %build_folder%\.cmake\api\v1\query\client-MicrosoftVS
xcopy query.json %build_folder%\.cmake\api\v1\query\client-MicrosoftVS
conan install . design-patterns/1.0.0@test/stable -s build_type=%build_type% --install-folder %install_folder%
xcopy %install_folder%\conanbuildinfo.txt %build_folder%
xcopy %install_folder%\conanbuildinfo.cmake %build_folder%
conan build . --install-folder %install_folder% --build-folder %build_folder% --configure