# Vaccine Tracking System

## This program allows User to enter their data and their Vaccine status and get put in a waiting list if unvaccinated. An admin can view the data of Users and can check the waiting list.

# Important installation notes:

## This program requires the installation of Qt 6.5.0 with the additional options: mingw_64, msvc2019_64, msvc2019_arm64.

## Vital steps in Visual Studio after installing Qt 6.5.0:
###	1) Making sure to install the Qt extension within Visual Studio.
###	2) Setting the version within the extension to the MSVC compiler inside the 6.5.0 folder within Qt folder.
###	3) Including the Qt path inside Visual Studio solution properties. Has to be included under c++>General and Linker>Input for both Debug and Release configuration.