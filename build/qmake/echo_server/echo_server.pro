QT       -= core gui
TARGET   =  echo_server
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE =  app

SOURCES  += ../../../src/ma/console_controller.cpp \
            ../../../src/echo_server/main.cpp \
            ../../../src/ma/echo/server/session_config.cpp \
            ../../../src/ma/echo/server/session_manager_config.cpp \
            ../../../src/ma/echo/server/session.cpp \
            ../../../src/ma/echo/server/session_manager.cpp

		
HEADERS  += ../../../include/ma/handler_storage_service.hpp \
            ../../../include/ma/handler_storage.hpp \
            ../../../include/ma/handler_invoke_helpers.hpp \
            ../../../include/ma/bind_asio_handler.hpp \
            ../../../include/ma/handler_allocation.hpp \
            ../../../include/ma/handler_alloc_helpers.hpp \
            ../../../include/ma/cyclic_buffer.hpp \
            ../../../include/ma/console_controller.hpp \
            ../../../include/ma/echo/server/session_config_fwd.hpp \
            ../../../include/ma/echo/server/session_manager_config_fwd.hpp \
            ../../../include/ma/echo/server/session_config.hpp \
            ../../../include/ma/echo/server/session_manager_config.hpp \
            ../../../include/ma/echo/server/session_fwd.hpp \
            ../../../include/ma/echo/server/session_manager_fwd.hpp \
            ../../../include/ma/echo/server/session.hpp \
            ../../../include/ma/echo/server/session_manager.hpp
		

LIBS        += -L../../../../boost_1_44_0/lib/x86
INCLUDEPATH += ../../../../boost_1_44_0 \
               ../../../include
DEFINES     += WIN32_LEAN_AND_MEAN BOOST_HAS_THREADS _UNICODE UNICODE
