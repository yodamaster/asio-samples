//
// Copyright (c) 2010-2011 Marat Abrarov (abrarov@mail.ru)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef MA_ECHO_SERVER_QT_SERVICE_H
#define MA_ECHO_SERVER_QT_SERVICE_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <cstddef>
#include <boost/scoped_ptr.hpp>
#include <boost/system/error_code.hpp>
#include <QtCore/QObject>
#include <ma/echo/server/session_manager_config_fwd.hpp>
#include <ma/echo/server/qt/service_fwd.h>

namespace ma
{    
  namespace echo
  {
    namespace server
    {    
      namespace qt 
      {
        struct execution_config
        {
          std::size_t session_manager_thread_count;
          std::size_t session_thread_count;
          long stop_sec_timeout;

          execution_config(std::size_t the_session_manager_thread_count, 
            std::size_t the_session_thread_count, long the_stop_sec_timeout);
        }; // struct execution_config

        class Service : public QObject
        {
          Q_OBJECT

        public:
          explicit Service(QObject* parent = 0);
          ~Service();

          void asyncStart(const execution_config&, const session_manager_config&);
          void asyncWait();
          void asyncStop();

        signals:
          void startComplete(const boost::system::error_code& error);
          void waitComplete(const boost::system::error_code& error);
          void stopComplete(const boost::system::error_code& error);

        private:
          class implementation;

          Q_DISABLE_COPY(Service);          

          boost::scoped_ptr<implementation> impl_;    
        }; // class Service

      } // namespace qt
    } // namespace server
  } // namespace echo
} // namespace ma

#endif // MA_ECHO_SERVER_QT_SERVICE_H
