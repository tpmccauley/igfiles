find_package(PkgConfig)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(IgFiles_PKGCONF IgFiles)
endif (PKG_CONFIG_FOUND)

find_path(IgFiles_INCLUDE_DIRS NAMES IgArchive.h PATHS ${IgFiles_PKGCONF_INCLUDE_DIRS})

find_library(IgFiles_LIBRARIES NAMES libIgFiles.a PATHS ${IgFiles_PKGCONF_LIBRARY_DIRS})
