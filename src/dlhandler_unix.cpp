/***************************************************************************
 *   Copyright (C) 2009-2019 by CNRS and University of Strasbourg          *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02111-1301, USA.         *
 ***************************************************************************/

/**
 * This file is part of the Mychem software. It contains functions declaration
 * used by Mychem and related to dynamic library management.
 * @file dlhandler_unix.cpp
 * @short Dynamic library management.
 * @author Jerome Pansanel <jerome.pansanel@iphc.cnrs.fr>
 */

#include <mychem/config.h>
#include <mychem/dlhandler.h>

#include <dlfcn.h>
#include <cstdio>

using namespace std;

void *LibHandler::lib_handler = NULL;

LibHandler::LibHandler()
{
  if (!lib_handler) {
    lib_handler = dlopen(OB_LIBRARY_FILE, RTLD_LAZY | RTLD_GLOBAL);
  }
}

LibHandler::~LibHandler()
{
  if (lib_handler) {
    dlclose(lib_handler);
  }
}

bool LibHandler::isLoaded() {
  if (lib_handler) {
    return true;
  }
  else {
    return false;
  }
}

