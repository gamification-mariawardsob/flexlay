//  $Id$
//
//  Flexlay - A Generic 2D Game Editor
//  Copyright (C) 2002 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#include <iostream>
#include <ClanLib/Display/display.h>
#include <ClanLib/Core/Math/origin.h>
#include <ClanLib/Core/System/error.h>
#include "objmap_object.hxx"
#include "objmap_sprite_object.hxx"
#include "editor_objmap.hxx"

extern CL_ResourceManager* resources;
ObjectLayer* ObjectLayer::current_ = 0;

ObjectLayer::ObjectLayer()
{
  handle_count = 0;
}

ObjectLayer::~ObjectLayer()
{
}

void
ObjectLayer::draw(EditorMapComponent* parent)
{
  for(Objs::iterator i = objects.begin(); i != objects.end(); ++i)
    {
      (*i)->draw();
    }
}

int
ObjectLayer::duplicate_object(int id)
{
  ObjMapObject* obj    = get_object(id);
  ObjMapObject* newobj = obj->duplicate(++handle_count);
  objects.push_back(newobj);  

  // FIXME: Move to scripting level
  newobj->set_pos(newobj->get_pos() + CL_Point(16, 16));

  return newobj->get_handle();
}

#ifdef SWIGGUILE
int
ObjectLayer::add_object(const CL_Sprite& sprite, const CL_Point& pos, const SCMObj& data)
{
  ObjMapObject* obj = new ObjMapSpriteObject(++handle_count, pos, data, sprite);

  objects.push_back(obj);  

  return obj->get_handle();
}
#endif

ObjMapObject*
ObjectLayer::find_object(const CL_Point& click_pos)
{
  for(Objs::reverse_iterator i = objects.rbegin(); i != objects.rend(); ++i)
    {
      CL_Rect rect = (*i)->get_bound_rect();
     
      if (rect.is_inside(click_pos))
        return *i;
    }
  return 0;
}

void
ObjectLayer::delete_object(int id)
{
  for(Objs::iterator i = objects.begin(); i != objects.end(); ++i)
    {
      if ((*i)->get_handle() == id)
        {
          //delete *i;
          objects.erase(i);
          break;
        }
    }
}

std::vector<ObjectLayer::Obj*>
ObjectLayer::get_selection(const CL_Rect& rect)
{
  std::vector<ObjectLayer::Obj*> selection;

  for(Objs::iterator i = objects.begin(); i != objects.end(); ++i)
    {
      // FIXME:
      if (rect.is_inside((*i)->get_pos()))
        {
          selection.push_back(*i);
        }
    }
  
  return selection;
}

ObjectLayer::Obj*
ObjectLayer::get_object(int id)
{
  for(Objs::iterator i = objects.begin(); i != objects.end(); ++i)
    if ((*i)->get_handle() == id)
      return *i;
  return 0;
}

ObjectLayer::Objs*
ObjectLayer::get_objects()
{
  return &objects;
}

void
ObjectLayer::add_object(ObjMapObject* obj)
{
  objects.push_back(obj);
}

Layer
ObjectLayer::to_layer()
{
  //return Layer(impl);
  return Layer();
}

/* EOF */