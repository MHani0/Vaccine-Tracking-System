# Vaccine Tracking System <br>

### This program allows user to enter their data and their Vaccine status and get put in a waiting list if unvaccinated. An admin can view or delete the data of users, view insightful statistics of vaccinated or unvaccinated users and can check the vaccination waiting list. <br> <br>

## Important installation notes: <br>

### This program requires the installation of Qt 6.5.0 with the additional options: mingw_64, msvc2019_64, msvc2019_arm64. <br>

### Vital steps in Visual Studio after installing Qt 6.5.0:
####	1) Making sure to install the Qt extension within Visual Studio.
####	2) Setting the version within the extension to the MSVC compiler inside the 6.5.0 folder within Qt folder.
####	3) Including the Qt path inside Visual Studio solution properties. For both Debug and Release configurationhe, Qt's Include folder has to be included under c++>General and the Qt's lib folder has to be included under Linker>General.
##### [In some cases, Qt's extra dependencies don't get included, if that happens, manually add the needed libraries in the Linker>Input. The only extra dependency used is qdebug (library name: qtd{version}{platform}d.lib and qt{version}core.lib), the name could be different depending on the version and compiler chosen. An alternative to this would be to simply remove the inlcusion of qdebug.h inside main.h and remove any qDebug() function within the whole code]
