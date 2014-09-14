# Flexlay - A Generic 2D Game Editor
# Copyright (C) 2014 Ingo Ruhnke <grumbel@gmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.


import os


class Config:
    current = None

    @staticmethod
    def create(projectname):
        dir = os.path.expanduser("~/.flexlay/")
        if not os.path.isdir(dir):
            os.mkdir(dir)

        return Config(os.path.join(dir, projectname))

    def __init__(self, filename):
        Config.current = self

        self.datadir = ""
        self.recent_files = [
            "/home/ingo/projects/supertux/trunk/supertux/data/levels/world1/02 - The Journey Begins.stl"
        ]
        self.filename = filename

        if os.path.isfile(filename):
            pass  # GRUMBEL load the config file

    def save(self, filename=None):
        if filename is None:
            filename = self.filename

        with open(filename, "w") as f:
            f.write("# Autogenerated Script, don't edit by hand!\n\n")
            f.write("datadir = %r\n" % self.datadir)
            f.write("recent_files = %r\n" % self.recent_files)
            f.write("\n# EOF #\n")


# EOF #
