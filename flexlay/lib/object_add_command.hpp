//  $Id$
// 
//  Flexlay - A Generic 2D Game Editor
//  Copyright (C) 2002 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_OBJECT_ADD_COMMAND_HXX
#define HEADER_OBJECT_ADD_COMMAND_HXX

#include "objmap_object.hpp"
#include "command.hpp"

class ObjectLayer;
class ObjectAddCommandImpl;

/** ObjectAddCommand adds on object to an ObjectLayer, the user needs
    to supply an Object together with the \a ObjectLayer to which it
    should be added. FIXME: position should be part of the command,
    not the object */
class ObjectAddCommand
{
public:
  ObjectAddCommand(const ObjectLayer& layer);
  virtual ~ObjectAddCommand();

  void add_object(const ObjMapObject& obj);

  //int get_handle() const;

  Command to_command();

private:
  SharedPtr<ObjectAddCommandImpl> impl;
};

#endif

/* EOF */