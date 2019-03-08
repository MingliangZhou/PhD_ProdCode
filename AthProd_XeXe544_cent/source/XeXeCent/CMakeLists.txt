## automatically generated CMakeLists.txt file

# Declare the package
atlas_subdir( XeXeCent )

# Declare external dependencies ... default here is to include ROOT
find_package( ROOT COMPONENTS MathCore RIO Core Tree Hist )

# Declare public and private dependencies
# Public dependencies are anything that appears in the headers in public include dir
# Private is anything else

# An example is included
atlas_depends_on_subdirs(
    PUBLIC

    PRIVATE
    Control/AthAnalysisBaseComps
)

# Declare package as a library
# Note the convention that library names get "Lib" suffix
# Any package you add to dependencies above, you should add
# to LINK_LIBRARIES line below (see the example)
atlas_add_library( XeXeCentLib src/*.cxx
                   PUBLIC_HEADERS XeXeCent
                   INCLUDE_DIRS ${ROOT_INCLUDE_DIRS}
                   LINK_LIBRARIES ${ROOT_LIBRARIES}
                                    AthAnalysisBaseCompsLib AsgTools TrigDecisionTool xAODTracking xAODEventInfo xAODHIEvent xAODCaloEvent
)

# if you add components (tools, algorithms) to this package
# these lines are needed so you can configure them in joboptions
atlas_add_component( XeXeCent src/components/*.cxx
                      LINK_LIBRARIES XeXeCentLib 
)

# if you add an application (exe) to this package
# declare it like this (note convention that apps go in the util dir)
# atlas_add_executable( MyApp util/myApp.cxx
#                       LINK_LIBRARIES XeXeCentLib
# )

# Install python modules, joboptions, and share content
atlas_install_python_modules( python/*.py )
atlas_install_joboptions( share/*.py )
atlas_install_data( data/* )
# You can access your data from code using path resolver, e.g.
# PathResolverFindCalibFile("XeXeCent/file.txt")



