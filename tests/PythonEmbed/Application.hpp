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
 * @file   Elements/tests/PythonEmbed/Application.hpp
 * @author Karen Arutyunov
 * $Id:$
 */

#ifndef _ELEMENTS_TESTS_PYTHONEMBED_APPLICATION_HPP_
#define _ELEMENTS_TESTS_PYTHONEMBED_APPLICATION_HPP_

#include <string>
#include <list>

#include <ace/OS.h>
#include <ace/Synch.h>
#include <ace/Guard_T.h>

#include <Python.h>

#include <El/Exception.hpp>
#include <El/Service/Service.hpp>

#include <El/Python/RefCount.hpp>
#include <El/Python/Code.hpp>

class Application : public El::Service::Callback
{
public:    
    EL_EXCEPTION(Exception, El::ExceptionBase);
    EL_EXCEPTION(InvalidArg, Exception);
    
public:
    
  Application() throw(Exception, El::Exception);
  virtual ~Application() throw();

  int run(int& argc, char** argv) throw(InvalidArg, Exception, El::Exception);

private:

  virtual bool notify(El::Service::Event* event) throw(El::Exception);
  
  struct Argument
  {
    std::string name;
    std::string value;

    Argument(const char* nm = 0, const char* vl = 0)
      throw(El::Exception);
  };
  
  typedef std::list<Argument> ArgList;

  int help(const ArgList& arguments)
    throw(InvalidArg, Exception, El::Exception);

  int test(const ArgList& arguments)
    throw(InvalidArg, Exception, El::Exception);

private:
  typedef ACE_Thread_Mutex  Mutex;
  typedef ACE_Guard<Mutex>  ReadGuard;
  typedef ACE_Guard<Mutex>  WriteGuard;

  mutable Mutex lock_;

  unsigned long counter_;
  El::Service::ThreadPool_var thread_pool_;

  El::Python::Code code_;
};

///////////////////////////////////////////////////////////////////////////////
// Inlines
///////////////////////////////////////////////////////////////////////////////

//
// Application::Argument class
//
inline
Application::Argument::Argument(const char* nm, const char* vl)
  throw(El::Exception)
    : name(nm ? nm : ""),
      value(vl ? vl : "")
{
}

#endif // _ELEMENTS_TESTS_PYTHONEMBED_APPLICATION_HPP_