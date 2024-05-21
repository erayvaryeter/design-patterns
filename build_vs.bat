@echo off
SetLocal EnableDelayedExpansion

set configuration_param=%1
call cmake_builder.bat Initialize
set base_install_folder=C:\\.conan\\INSTALL\\
set base_build_folder=C:\\.conan\\BUILD\\
set project_install_folder=%base_install_folder%%project_name%\\
set project_build_folder=%base_build_folder%%project_name%\\
set conan_build_command=conan build .
set conan_export_command=conan export-pkg .

if %configuration_param%==Windows-Debug (
	set project_install_folder=%project_install_folder%win-debug
	set project_build_folder=%project_build_folder%win-debug
)

if %configuration_param%==Windows-Release (
	set project_install_folder=%project_install_folder%win-release
	set project_build_folder=%project_build_folder%win-release
)

set conan_build_command=%conan_build_command% --install-folder %project_install_folder% --build-folder %project_build_folder% --build
set conan_export_command=%conan_export_command% --install-folder %project_install_folder% --build-folder %project_build_folder%

%conan_build_command%
%conan_export_command%