add_library(Gameplay)

plasma_setup_library(Gameplay ${CMAKE_CURRENT_LIST_DIR} TRUE)
plasma_use_precompiled_header(Gameplay ${CMAKE_CURRENT_LIST_DIR})

target_sources(Gameplay
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/CameraViewport.cpp
    ${CMAKE_CURRENT_LIST_DIR}/CameraViewport.hpp
    ${CMAKE_CURRENT_LIST_DIR}/CsgExternalSerialization.hpp
    ${CMAKE_CURRENT_LIST_DIR}/DefaultGame.cpp
    ${CMAKE_CURRENT_LIST_DIR}/DefaultGame.hpp
    ${CMAKE_CURRENT_LIST_DIR}/EmscriptenExportTarget.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Exporter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Exporter.hpp
    ${CMAKE_CURRENT_LIST_DIR}/GameplayStandard.cpp
    ${CMAKE_CURRENT_LIST_DIR}/GameplayStandard.hpp
    ${CMAKE_CURRENT_LIST_DIR}/GitJobs.cpp
    ${CMAKE_CURRENT_LIST_DIR}/GitJobs.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Importer.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Importer.hpp
    ${CMAKE_CURRENT_LIST_DIR}/IndexedHalfEdgeMesh.cpp
    ${CMAKE_CURRENT_LIST_DIR}/IndexedHalfEdgeMesh.hpp
    ${CMAKE_CURRENT_LIST_DIR}/MarchingCubes.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MarchingCubes.hpp
    ${CMAKE_CURRENT_LIST_DIR}/MarchingSquares.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MarchingSquares.hpp
    ${CMAKE_CURRENT_LIST_DIR}/MouseCapture.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MouseCapture.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Orientation.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Orientation.hpp
    ${CMAKE_CURRENT_LIST_DIR}/PathFinder.cpp
    ${CMAKE_CURRENT_LIST_DIR}/PathFinder.hpp
    ${CMAKE_CURRENT_LIST_DIR}/PathFinderGrid.cpp
    ${CMAKE_CURRENT_LIST_DIR}/PathFinderGrid.hpp
    ${CMAKE_CURRENT_LIST_DIR}/PathFinderMesh.cpp
    ${CMAKE_CURRENT_LIST_DIR}/PathFinderMesh.hpp
    ${CMAKE_CURRENT_LIST_DIR}/PlayGame.cpp
    ${CMAKE_CURRENT_LIST_DIR}/PlayGame.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Precompiled.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Precompiled.hpp
    ${CMAKE_CURRENT_LIST_DIR}/PriorityQueue.hpp
    ${CMAKE_CURRENT_LIST_DIR}/QuickHull3DBindings.cpp
    ${CMAKE_CURRENT_LIST_DIR}/QuickHull3DBindings.hpp
    ${CMAKE_CURRENT_LIST_DIR}/RandomContext.cpp
    ${CMAKE_CURRENT_LIST_DIR}/RandomContext.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Reactive.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Reactive.hpp
    ${CMAKE_CURRENT_LIST_DIR}/ReactiveViewport.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ReactiveViewport.hpp
    ${CMAKE_CURRENT_LIST_DIR}/SplineParticles.cpp
    ${CMAKE_CURRENT_LIST_DIR}/SplineParticles.hpp
    ${CMAKE_CURRENT_LIST_DIR}/TileMap.cpp
    ${CMAKE_CURRENT_LIST_DIR}/TileMap.hpp
    ${CMAKE_CURRENT_LIST_DIR}/TileMapSource.cpp
    ${CMAKE_CURRENT_LIST_DIR}/TileMapSource.hpp
    ${CMAKE_CURRENT_LIST_DIR}/TileMapSourceLoadPattern.hpp
    ${CMAKE_CURRENT_LIST_DIR}/UnitTestSystem.cpp
    ${CMAKE_CURRENT_LIST_DIR}/UnitTestSystem.hpp
    ${CMAKE_CURRENT_LIST_DIR}/WindowsExportTarget.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Plasma.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Plasma.hpp
)

plasma_target_includes(Gameplay
  PUBLIC
    Common
    Lightning
    Engine
    LightningShaders
    tracy
)

set_target_properties( Gameplay PROPERTIES FOLDER "PlasmaEngine" )
