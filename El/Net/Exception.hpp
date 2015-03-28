/*
 * Elements - useful abstractions library.
 * Copyright (C) 2005-2015 Karen Arutyunov
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

/**
 * @file Elements/El/Net/Exception.hpp
 * @author Karen Arutyunov
 * $id:$
 */

#ifndef _ELEMENTS_EL_NET_EXCEPTION_HPP_
#define _ELEMENTS_EL_NET_EXCEPTION_HPP_

#include <El/Exception.hpp>

namespace El
{
  namespace Net
  {
    EL_EXCEPTION(Exception, El::ExceptionBase);
  }
}


#endif // _ELEMENTS_EL_NET_EXCEPTION_HPP_