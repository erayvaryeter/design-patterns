@echo off
SetLocal EnableDelayedExpansion

set configuration_param=%1
call cmake_builder.bat Initialize
set base_install_folder=C:\\.conan\\INSTALL\\
set base_build_folder=C:\\.conan\\BUILD\\
set project_install_folder=%base_install_folder%%project_name%\\
set project_build_folder=%base_build_folder%%project_name%\\
set conan_install_command=conan install . %project_name%/%project_version%@%username%/%channel%
set conan_build_command=conan build .

if %configuration_param%==Windows-Debug (
	set project_install_folder=%project_install_folder%win-debug
	set project_build_folder=%project_build_folder%win-debug
	set conan_install_command=%conan_install_command% -s build_type=Debug
)

if %configuration_param%==Windows-Release (
	set project_install_folder=%project_install_folder%win-release
	set project_build_folder=%project_build_folder%win-release
	set conan_install_command=%conan_install_command% -s build_type=Release
)

set conan_install_command=%conan_install_command% --install-folder %project_install_folder%
set conan_build_command=%conan_build_command% --install-folder %project_install_folder% --build-folder %project_build_folder% --configure

if exist %project_install_folder%\ (
	rmdir /s /q %project_install_folder%
	mkdir %project_install_folder%
)

if exist %project_build_folder%\ (
	rmdir /s /q %project_build_folder%
	mkdir %project_build_folder%
)

%conan_install_command%
xcopy %project_install_folder%\conanbuildinfo.txt %project_build_folder%
xcopy %project_install_folder%\conanbuildinfo.cmake %project_build_folder%
%conan_build_command%

set /A includes_started=0
set /A includes_finished=0
set nmake_includes=

for /f "tokens=*" %%a in (%project_install_folder%\conanbuildinfo.txt) do (
	if %%a==[libdirs] (
		set /A includes_finished=1
	)
	if !includes_started!==1 (
		if !includes_finished!==0 (
			set nmake_includes=!nmake_includes!%%a;
		)
	)
	if %%a==[includedirs] (
		set /A includes_started=1
	)
)

set comment=COPY THE FOLLOWING LINE TO NMake: Include Search Path
echo %comment%
echo %nmake_includes%