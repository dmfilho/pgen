/**
 * pgen, Parser Generator.
 * Copyright (C) 2015 Dimas Melo Filho
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA. 
 * 
 * The author can be reached by e-mail: dldmf@cin.ufpe.br.
 * 
 * \author Dimas Melo Filho <dldmf@cin.ufpe.br>
 * \date 2015-12-01
 */

#ifndef __NAMEINDEXER_H__
#define __NAMEINDEXER_H__

#include <string>
#include <unordered_map>

using namespace std;

namespace pgen
{
	class NameIndexer
	{
	private:
		static unordered_map<string, int> nameMap;		// Map of Name -> id
		static int count;								// Id count
	public:
		static string get(string fndef);
	};
}

#endif /* __NAMEINDEXER_H__ */