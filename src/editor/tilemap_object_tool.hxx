//  $Id: tilemap_object_tool.hxx,v 1.1 2003/09/23 22:10:40 grumbel Exp $
// 
//  Pingus - A free Lemmings clone
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

#ifndef HEADER_TILEMAP_OBJECT_TOOL_HXX
#define HEADER_TILEMAP_OBJECT_TOOL_HXX

#include "tilemap_tool.hxx"
#include "editor_objmap.hxx"
#include "object_brush.hxx"

class EditorMap;

/** */
class TileMapObjectTool : public TileMapTool
{
private:
  EditorObjMap* objmap;
  EditorObjMap::Obj* obj;
  enum { DRAG, SELECT, NONE } state;

  /** the position on which the object was clicked, relative to the
      object */
  CL_Point offset;

  CL_Point drag_start;
  CL_Rect selection_rect;

  typedef std::vector<EditorObjMap::Obj*> Selection; 
  Selection selection;
public:
  TileMapObjectTool(EditorMap* p, EditorObjMap* t);
  ~TileMapObjectTool();

  void draw();

  void on_mouse_up  (const CL_InputEvent& event);
  void on_mouse_down(const CL_InputEvent& event);
  void on_mouse_move(const CL_InputEvent& event);

private:
  TileMapObjectTool (const TileMapObjectTool&);
  TileMapObjectTool& operator= (const TileMapObjectTool&);
};

#endif

/* EOF */
