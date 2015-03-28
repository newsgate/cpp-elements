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

#include "Locale.hpp"

namespace El
{
  const Locale Locale::null(El::Lang(El::Lang::EC_NUL),
                            El::Country(El::Country::EC_NUL));

  const Locale Locale::nonexistent(El::Lang(El::Lang::EC_NONEXISTENT),
                                   El::Country(El::Country::EC_NONEXISTENT));
  
  const Locale Locale::nonexistent2(El::Lang(El::Lang::EC_NONEXISTENT2),
                                    El::Country(El::Country::EC_NONEXISTENT2));
}