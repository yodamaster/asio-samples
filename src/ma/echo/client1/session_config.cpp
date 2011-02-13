//
// Copyright (c) 2010-2011 Marat Abrarov (abrarov@mail.ru)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <stdexcept>
#include <boost/throw_exception.hpp>
#include <ma/echo/client1/session_config.hpp>

namespace ma
{    
  namespace echo
  {
    namespace client1
    {          
      session_config::session_config(std::size_t the_buffer_size, 
        const boost::optional<int>& the_socket_recv_buffer_size, 
        const boost::optional<int>& the_socket_send_buffer_size,
        const boost::optional<bool>& the_no_delay)
        : no_delay(the_no_delay)          
        , socket_recv_buffer_size(the_socket_recv_buffer_size)
        , socket_send_buffer_size(the_socket_send_buffer_size)
        , buffer_size(the_buffer_size)         
      {
        if (the_buffer_size < 1)
        {
          boost::throw_exception(std::invalid_argument(
            "the_buffer_size must be >= 1"));
        }
        if (the_socket_recv_buffer_size && (*the_socket_recv_buffer_size) < 0)
        {
          boost::throw_exception(std::invalid_argument(
            "the_socket_recv_buffer_size must be non negative"));
        }
        if (the_socket_send_buffer_size && (*the_socket_send_buffer_size) < 0)
        {
          boost::throw_exception(std::invalid_argument(
            "the_socket_send_buffer_size must be non negative"));
        }
      } // session_config::session_config
        
    } // namespace client1
  } // namespace echo
} // namespace ma
