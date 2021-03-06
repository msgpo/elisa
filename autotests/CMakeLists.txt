enable_testing()

configure_file(mediaplaylisttestconfig.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/mediaplaylisttestconfig.h @ONLY)

include_directories(${elisa_CURRENT_BINARY_DIR})
include_directories(${elisa_BINARY_DIR})
include_directories(${elisa_BINARY_DIR}/src)

set(databaseInterfaceTest_SOURCES
    ../src/databaseinterface.cpp
    ../src/musicartist.cpp
    ../src/musicalbum.cpp
    ../src/musicaudiotrack.cpp
    databaseinterfacetest.cpp
)

ecm_add_test(${databaseInterfaceTest_SOURCES}
    TEST_NAME "databaseInterfaceTest"
    LINK_LIBRARIES Qt5::Test Qt5::Core Qt5::Sql KF5::I18n)

target_include_directories(databaseInterfaceTest PRIVATE ${CMAKE_SOURCE_DIR}/src)

set(managemediaplayercontrolTest_SOURCES
    ../src/managemediaplayercontrol.cpp
    ../src/mediaplaylist.cpp
    ../src/databaseinterface.cpp
    ../src/musiclistenersmanager.cpp
    ../src/elisaapplication.cpp
    ../src/notificationitem.cpp
    ../src/trackslistener.cpp
    ../src/musicartist.cpp
    ../src/musicalbum.cpp
    ../src/musicaudiotrack.cpp
    ../src/elisautils.cpp
    ../src/file/filelistener.cpp
    ../src/file/localfilelisting.cpp
    ../src/abstractfile/abstractfilelistener.cpp
    ../src/abstractfile/abstractfilelisting.cpp
    managemediaplayercontroltest.cpp
)

if (KF5Baloo_FOUND)
    if (Qt5DBus_FOUND)
        qt5_add_dbus_interface(managemediaplayercontrolTest_SOURCES
            ${BALOO_DBUS_INTERFACES_DIR}/org.kde.baloo.fileindexer.xml
            baloo/fileindexer)

        qt5_add_dbus_interface(managemediaplayercontrolTest_SOURCES
            ${BALOO_DBUS_INTERFACES_DIR}/org.kde.baloo.scheduler.xml
            baloo/scheduler)

        set(managemediaplayercontrolTest_SOURCES
            ${managemediaplayercontrolTest_SOURCES}
            ../src/baloo/baloolistener.cpp
            ../src/baloo/localbaloofilelisting.cpp
            )
    endif()
endif()

if (UPNPQT_FOUND)
    set(managemediaplayercontrolTest_SOURCES
        ${managemediaplayercontrolTest_SOURCES}
        ../src/upnp/upnpcontrolcontentdirectory.cpp
        ../src/upnp/upnpcontentdirectorymodel.cpp
        ../src/upnp/upnpcontrolconnectionmanager.cpp
        ../src/upnp/upnpcontrolmediaserver.cpp
        ../src/upnp/didlparser.cpp
        ../src/upnp/upnplistener.cpp
        ../src/upnp/upnpdiscoverallmusic.cpp
        )
endif()

kconfig_add_kcfg_files(managemediaplayercontrolTest_SOURCES ../src/elisa_settings.kcfgc )
set(managemediaplayercontrolTest_SOURCES
    ${managemediaplayercontrolTest_SOURCES}
    ../src/elisa_core.kcfg
)

ecm_add_test(${managemediaplayercontrolTest_SOURCES}
    TEST_NAME "managemediaplayercontrolTest"
    LINK_LIBRARIES
        Qt5::Test Qt5::Core Qt5::Sql Qt5::Widgets KF5::I18n Qt5::Quick Qt5::Multimedia KF5::ConfigCore KF5::ConfigGui KF5::FileMetaData
)

if (KF5Baloo_FOUND)
    target_link_libraries(managemediaplayercontrolTest KF5::Baloo Qt5::DBus)
endif()
if (KF5KCMUtils_FOUND)
    target_link_libraries(managemediaplayercontrolTest KF5::KCMUtils)
endif()
if (UPNPQT_FOUND)
    target_link_libraries(managemediaplayercontrolTest Qt5::Xml UPNP::upnpQt Qt5::Network)
endif()
if (KF5XmlGui_FOUND)
    target_link_libraries(managemediaplayercontrolTest KF5::XmlGui)
endif()

target_include_directories(managemediaplayercontrolTest PRIVATE ${CMAKE_SOURCE_DIR}/src)

set(manageheaderbarTest_SOURCES
    ../src/manageheaderbar.cpp
    ../src/mediaplaylist.cpp
    ../src/databaseinterface.cpp
    ../src/musiclistenersmanager.cpp
    ../src/elisaapplication.cpp
    ../src/notificationitem.cpp
    ../src/trackslistener.cpp
    ../src/trackslistener.cpp
    ../src/musicartist.cpp
    ../src/musicalbum.cpp
    ../src/musicaudiotrack.cpp
    ../src/elisautils.cpp
    ../src/file/filelistener.cpp
    ../src/file/localfilelisting.cpp
    ../src/abstractfile/abstractfilelistener.cpp
    ../src/abstractfile/abstractfilelisting.cpp
    manageheaderbartest.cpp
)

if (KF5Baloo_FOUND)
    if (Qt5DBus_FOUND)
        qt5_add_dbus_interface(manageheaderbarTest_SOURCES
            ${BALOO_DBUS_INTERFACES_DIR}/org.kde.baloo.fileindexer.xml
            baloo/fileindexer)

        qt5_add_dbus_interface(manageheaderbarTest_SOURCES
            ${BALOO_DBUS_INTERFACES_DIR}/org.kde.baloo.scheduler.xml
            baloo/scheduler)

        set(manageheaderbarTest_SOURCES
            ${manageheaderbarTest_SOURCES}
            ../src/baloo/baloolistener.cpp
            ../src/baloo/localbaloofilelisting.cpp
            )
    endif()
endif()

if (UPNPQT_FOUND)
    set(manageheaderbarTest_SOURCES
        ${manageheaderbarTest_SOURCES}
        ../src/upnp/upnpcontrolcontentdirectory.cpp
        ../src/upnp/upnpcontentdirectorymodel.cpp
        ../src/upnp/upnpcontrolconnectionmanager.cpp
        ../src/upnp/upnpcontrolmediaserver.cpp
        ../src/upnp/didlparser.cpp
        ../src/upnp/upnplistener.cpp
        ../src/upnp/upnpdiscoverallmusic.cpp
        )
endif()

kconfig_add_kcfg_files(manageheaderbarTest_SOURCES ../src/elisa_settings.kcfgc )
set(manageheaderbarTest_SOURCES
    ${manageheaderbarTest_SOURCES}
    ../src/elisa_core.kcfg
)

ecm_add_test(${manageheaderbarTest_SOURCES}
    TEST_NAME "manageheaderbarTest"
    LINK_LIBRARIES
        Qt5::Test Qt5::Core Qt5::Sql Qt5::Gui Qt5::Widgets KF5::I18n Qt5::Quick Qt5::Multimedia KF5::ConfigCore KF5::ConfigGui KF5::FileMetaData
)

if (KF5Baloo_FOUND)
    target_link_libraries(manageheaderbarTest KF5::Baloo Qt5::DBus)
endif()
if (KF5KCMUtils_FOUND)
    target_link_libraries(manageheaderbarTest KF5::KCMUtils)
endif()
if (UPNPQT_FOUND)
    target_link_libraries(manageheaderbarTest Qt5::Xml UPNP::upnpQt Qt5::Network)
endif()
if (KF5XmlGui_FOUND)
    target_link_libraries(manageheaderbarTest KF5::XmlGui)
endif()

target_include_directories(manageheaderbarTest PRIVATE ${CMAKE_SOURCE_DIR}/src)

set(manageaudioplayerTest_SOURCES
    ../src/manageaudioplayer.cpp
    manageaudioplayertest.cpp
)

ecm_add_test(${manageaudioplayerTest_SOURCES}
    TEST_NAME "manageaudioplayerTest"
    LINK_LIBRARIES Qt5::Test Qt5::Core Qt5::Gui Qt5::Multimedia)

target_include_directories(manageaudioplayerTest PRIVATE ${CMAKE_SOURCE_DIR}/src)

set(mediaplaylistTest_SOURCES
    ../src/mediaplaylist.cpp
    ../src/databaseinterface.cpp
    ../src/trackslistener.cpp
    ../src/musiclistenersmanager.cpp
    ../src/elisaapplication.cpp
    ../src/notificationitem.cpp
    ../src/musicartist.cpp
    ../src/musicalbum.cpp
    ../src/musicaudiotrack.cpp
    ../src/elisautils.cpp
    ../src/file/filelistener.cpp
    ../src/file/localfilelisting.cpp
    ../src/abstractfile/abstractfilelistener.cpp
    ../src/abstractfile/abstractfilelisting.cpp
    mediaplaylisttest.cpp
)

if (KF5Baloo_FOUND)
    if (Qt5DBus_FOUND)
        qt5_add_dbus_interface(mediaplaylistTest_SOURCES
            ${BALOO_DBUS_INTERFACES_DIR}/org.kde.baloo.fileindexer.xml
            baloo/fileindexer)

        qt5_add_dbus_interface(mediaplaylistTest_SOURCES
            ${BALOO_DBUS_INTERFACES_DIR}/org.kde.baloo.scheduler.xml
            baloo/scheduler)

        set(mediaplaylistTest_SOURCES
            ${mediaplaylistTest_SOURCES}
            ../src/baloo/baloolistener.cpp
            ../src/baloo/localbaloofilelisting.cpp
            )
    endif()
endif()

if (UPNPQT_FOUND)
    set(mediaplaylistTest_SOURCES
        ${mediaplaylistTest_SOURCES}
        ../src/upnp/upnpcontrolcontentdirectory.cpp
        ../src/upnp/upnpcontentdirectorymodel.cpp
        ../src/upnp/upnpcontrolconnectionmanager.cpp
        ../src/upnp/upnpcontrolmediaserver.cpp
        ../src/upnp/didlparser.cpp
        ../src/upnp/upnplistener.cpp
        ../src/upnp/upnpdiscoverallmusic.cpp
        )
endif()

kconfig_add_kcfg_files(mediaplaylistTest_SOURCES ../src/elisa_settings.kcfgc )
set(mediaplaylistTest_SOURCES
    ${mediaplaylistTest_SOURCES}
    ../src/elisa_core.kcfg
)

ecm_add_test(${mediaplaylistTest_SOURCES}
    TEST_NAME "mediaplaylistTest"
    LINK_LIBRARIES
        Qt5::Test Qt5::Core Qt5::Sql Qt5::Gui Qt5::Widgets KF5::I18n Qt5::Quick Qt5::Multimedia KF5::ConfigCore KF5::ConfigGui KF5::FileMetaData
)

if (KF5Baloo_FOUND)
    target_link_libraries(mediaplaylistTest KF5::Baloo Qt5::DBus)
endif()
if (KF5KCMUtils_FOUND)
    target_link_libraries(mediaplaylistTest KF5::KCMUtils)
endif()
if (UPNPQT_FOUND)
    target_link_libraries(mediaplaylistTest Qt5::Xml UPNP::upnpQt Qt5::Network)
endif()
if (KF5XmlGui_FOUND)
    target_link_libraries(mediaplaylistTest KF5::XmlGui)
endif()

target_include_directories(mediaplaylistTest PRIVATE ${CMAKE_SOURCE_DIR}/src)

set(trackslistenertest_SOURCES
    ../src/mediaplaylist.cpp
    ../src/databaseinterface.cpp
    ../src/trackslistener.cpp
    ../src/musiclistenersmanager.cpp
    ../src/elisaapplication.cpp
    ../src/notificationitem.cpp
    ../src/musicartist.cpp
    ../src/musicalbum.cpp
    ../src/musicaudiotrack.cpp
    ../src/elisautils.cpp
    ../src/file/filelistener.cpp
    ../src/file/localfilelisting.cpp
    ../src/abstractfile/abstractfilelistener.cpp
    ../src/abstractfile/abstractfilelisting.cpp
    trackslistenertest.cpp
)

if (KF5Baloo_FOUND)
    if (Qt5DBus_FOUND)
        qt5_add_dbus_interface(trackslistenertest_SOURCES
            ${BALOO_DBUS_INTERFACES_DIR}/org.kde.baloo.fileindexer.xml
            baloo/fileindexer)

        qt5_add_dbus_interface(trackslistenertest_SOURCES
            ${BALOO_DBUS_INTERFACES_DIR}/org.kde.baloo.scheduler.xml
            baloo/scheduler)

        set(trackslistenertest_SOURCES
            ${trackslistenertest_SOURCES}
            ../src/baloo/baloolistener.cpp
            ../src/baloo/localbaloofilelisting.cpp
            )
    endif()
endif()

if (UPNPQT_FOUND)
    set(trackslistenertest_SOURCES
        ${trackslistenertest_SOURCES}
        ../src/upnp/upnpcontrolcontentdirectory.cpp
        ../src/upnp/upnpcontentdirectorymodel.cpp
        ../src/upnp/upnpcontrolconnectionmanager.cpp
        ../src/upnp/upnpcontrolmediaserver.cpp
        ../src/upnp/didlparser.cpp
        ../src/upnp/upnplistener.cpp
        ../src/upnp/upnpdiscoverallmusic.cpp
        )
endif()

kconfig_add_kcfg_files(trackslistenertest_SOURCES ../src/elisa_settings.kcfgc )
set(trackslistenertest_SOURCES
    ${trackslistenertest_SOURCES}
    ../src/elisa_core.kcfg
)

ecm_add_test(${trackslistenertest_SOURCES}
    TEST_NAME "trackslistenertest"
    LINK_LIBRARIES
        Qt5::Test Qt5::Core Qt5::Sql Qt5::Gui Qt5::Widgets KF5::I18n Qt5::Quick Qt5::Multimedia KF5::ConfigCore KF5::ConfigGui KF5::FileMetaData
)

if (KF5Baloo_FOUND)
    target_link_libraries(trackslistenertest KF5::Baloo Qt5::DBus)
endif()
if (KF5KCMUtils_FOUND)
    target_link_libraries(trackslistenertest KF5::KCMUtils)
endif()
if (UPNPQT_FOUND)
    target_link_libraries(trackslistenertest Qt5::Xml UPNP::upnpQt Qt5::Network)
endif()
if (KF5XmlGui_FOUND)
    target_link_libraries(trackslistenertest KF5::XmlGui)
endif()

target_include_directories(trackslistenertest PRIVATE ${CMAKE_SOURCE_DIR}/src)

set(allalbumsmodeltest_SOURCES
    ../src/databaseinterface.cpp
    ../src/musicartist.cpp
    ../src/musicalbum.cpp
    ../src/musicaudiotrack.cpp
    ../src/allalbumsmodel.cpp
    allalbumsmodeltest.cpp
)

ecm_add_test(${allalbumsmodeltest_SOURCES}
    TEST_NAME "allalbumsmodeltest"
    LINK_LIBRARIES Qt5::Test Qt5::Core Qt5::Sql KF5::I18n)

target_include_directories(allalbumsmodeltest PRIVATE ${CMAKE_SOURCE_DIR}/src)

set(albummodeltest_SOURCES
    ../src/databaseinterface.cpp
    ../src/musicartist.cpp
    ../src/musicalbum.cpp
    ../src/musicaudiotrack.cpp
    ../src/albummodel.cpp
    albummodeltest.cpp
)

ecm_add_test(${albummodeltest_SOURCES}
    TEST_NAME "albummodeltest"
    LINK_LIBRARIES Qt5::Test Qt5::Core Qt5::Sql KF5::I18n)

target_include_directories(albummodeltest PRIVATE ${CMAKE_SOURCE_DIR}/src)

set(allartistsmodeltest_SOURCES
    ../src/databaseinterface.cpp
    ../src/musicartist.cpp
    ../src/musicalbum.cpp
    ../src/musicaudiotrack.cpp
    ../src/allartistsmodel.cpp
    allartistsmodeltest.cpp
)

ecm_add_test(${allartistsmodeltest_SOURCES}
    TEST_NAME "allartistsmodeltest"
    LINK_LIBRARIES Qt5::Test Qt5::Core Qt5::Sql KF5::I18n)

target_include_directories(allartistsmodeltest PRIVATE ${CMAKE_SOURCE_DIR}/src)

set(alltracksmodeltest_SOURCES
    ../src/databaseinterface.cpp
    ../src/musicartist.cpp
    ../src/musicalbum.cpp
    ../src/musicaudiotrack.cpp
    ../src/alltracksmodel.cpp
    alltracksmodeltest.cpp
)

ecm_add_test(${alltracksmodeltest_SOURCES}
    TEST_NAME "alltracksmodeltest"
    LINK_LIBRARIES Qt5::Test Qt5::Core Qt5::Sql KF5::I18n)

target_include_directories(alltracksmodeltest PRIVATE ${CMAKE_SOURCE_DIR}/src)

set(localfilelistingtest_SOURCES
    ../src/file/localfilelisting.cpp
    ../src/abstractfile/abstractfilelisting.cpp
    ../src/musicaudiotrack.cpp
    ../src/notificationitem.cpp
    ../src/elisautils.cpp
    localfilelistingtest.cpp
)

kconfig_add_kcfg_files(localfilelistingtest_SOURCES ../src/elisa_settings.kcfgc )
set(localfilelistingtest_SOURCES
    ${localfilelistingtest_SOURCES}
    ../src/elisa_core.kcfg
)

ecm_add_test(${localfilelistingtest_SOURCES}
    TEST_NAME "localfilelistingtest"
    LINK_LIBRARIES Qt5::Test Qt5::Core Qt5::Sql KF5::I18n KF5::FileMetaData KF5::ConfigCore KF5::ConfigGui)

target_include_directories(localfilelistingtest PRIVATE ${CMAKE_SOURCE_DIR}/src)


if (KF5XmlGui_FOUND AND KF5KCMUtils_FOUND)
    set(elisaapplicationtest_SOURCES
        ../src/elisaapplication.cpp
        elisaapplicationtest.cpp
    )

    ecm_add_test(${elisaapplicationtest_SOURCES}
        TEST_NAME "elisaapplicationtest"
        LINK_LIBRARIES Qt5::Test Qt5::Core Qt5::Widgets KF5::ConfigCore KF5::ConfigGui KF5::ConfigWidgets KF5::XmlGui KF5::KCMUtils)

    target_include_directories(elisaapplicationtest PRIVATE ${CMAKE_SOURCE_DIR}/src)
endif()
