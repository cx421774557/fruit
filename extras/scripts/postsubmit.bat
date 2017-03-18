
echo Postsubmit.bat started.

if exist %VCVARSALL_SCRIPT% (
  CALL %VCVARSALL_SCRIPT% amd64
)

echo Creating build directory.

mkdir C:\Fruit\build-%CONFIGURATION%
cd C:\Fruit\build-%CONFIGURATION%

echo Running CMake.

%CMAKE_PATH%\cmake.exe -G %CMAKE_GENERATOR% .. -DCMAKE_BUILD_TYPE=%CONFIGURATION% -DBOOST_DIR=%BOOST_DIR% -DBUILD_TESTS_IN_RELEASE_MODE=True

echo Building Fruit.

IF %CMAKE_GENERATOR%=="MinGW Makefiles" (
  mingw32-make -j12
) ELSE (
  msbuild ALL_BUILD.vcxproj
)

echo Running tests.

%CMAKE_PATH%\ctest.exe -j 1 --output-on-failure -C %CONFIGURATION%
