//  $Id: windstille_menu.cxx,v 1.2 2003/09/29 19:56:42 grumbel Exp $
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

#include <config.h>
#include <iostream>
#include <ClanLib/Display/display.h>
#include <ClanLib/Display/keys.h>
#include <ClanLib/Core/System/system.h>
#include <ClanLib/Display/keyboard.h>
#include "globals.hxx"
#include "fonts.hxx"
#include "controller.hxx"
#include "windstille_menu.hxx"
#include "windstille_game.hxx"
#include "editor/editor.hxx"

WindstilleMenu::WindstilleMenu()
  : background("menu_background", resources),
    windstille("logo_large", resources)
{
  current_choice = 0;
  windstille.set_alignment(origin_top_center);
  passed_time = 0;
}

WindstilleMenu::~WindstilleMenu()
{
  
}

void
WindstilleMenu::update(float delta)
{
  passed_time += delta;

  background.update(delta);
  windstille.update(delta);

  if (CL_Keyboard::get_keycode(CL_KEY_ESCAPE))
    quit();

  Controller::Events& events = Controller::current()->get_events();

  for (Controller::Events::iterator i = events.begin();
       i != events.end(); ++i)
    {
      if ((*i).type == InputEvent::FIRE && (*i).state == true)
        {
          if (current_choice == 2) // QUIT
            quit();
          else if (current_choice == 0) // start game
            {
              WindstilleGame game(datadir + "levels/level9.scm");
              game.display ();
              break;
            }
          else if (current_choice == 1) // start editor
            {
              Editor editor;
              editor.run();
              break;
            }
        }
      else if (((*i).type == InputEvent::JUMP || (*i).type == InputEvent::UP)
               && (*i).state == true)
        {
          current_choice -= 1;
        }
      else if ((*i).type == InputEvent::DOWN && (*i).state == true)
        {
          current_choice += 1;
        }
    }

  while (CL_Keyboard::get_keycode(CL_KEY_ESCAPE))
    CL_System::keep_alive();

  if (current_choice < 0)
    current_choice = 2;
  else if (current_choice > 2)
    current_choice = 0;

  Controller::current()->clear();
}

void
WindstilleMenu::draw()
{
  //std::cout << "Draw... " << std::endl;
  background.draw(0,0);

  //windstille.set_alpha(sin(passed_time*3.141f)*.2f + .8f);
  windstille.draw(CL_Display::get_width()/2,
                  50);
  
  Fonts::menu.set_alignment(origin_bottom_center);
  Fonts::menu_h.set_alignment(origin_bottom_center);

  Fonts::menu_h.set_alpha(sin(passed_time*3.141f)*.4f + .6f);

  if (current_choice == 0)
    {
      Fonts::menu.draw(580, 330, "[Start Game]");
      Fonts::menu_h.draw(580, 330, "[Start Game]");
    }
  else
    Fonts::menu.draw(580, 330, "Start Game");

  if (current_choice == 1)
    {
      Fonts::menu.draw(580, 385, "[Start Editor]");
      Fonts::menu_h.draw(580, 385, "[Start Editor]");
    }
  else
    Fonts::menu.draw(580, 385, "Start Editor");

  if (current_choice == 2)
    {
      Fonts::menu.draw(580, 440, "[Quit]");
      Fonts::menu_h.draw(580, 440, "[Quit]");
    }
  else
    Fonts::menu.draw(580, 440, "Quit");
  
  Fonts::copyright.set_alignment(origin_bottom_left);
  Fonts::copyright.draw(15, CL_Display::get_height() - 10,
                        PACKAGE_STRING "\n"
                        "Copyright (c) 2003 Ingo Ruhnke <grumbel@gmx.de>\n"
                        "This game comes with ABSOLUTELY NO WARRANTY. This is free software, and you are welcome\n"
                        "to redistribute it under certain conditions; see the file COPYING for details.\n");

  CL_Display::flip();
}

/* EOF */