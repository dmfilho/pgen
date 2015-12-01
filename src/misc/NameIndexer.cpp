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
 
#include "NameIndexer.h"
#include <sstream>

using namespace std;

namespace pgen
{
	int NameIndexer::count = 1;
	unordered_map<string, int> NameIndexer::nameMap;
	
	string NameIndexer::get(string fndef)
	{
		int cid;
		auto nameit = NameIndexer::nameMap.find(fndef);
		if (nameit == NameIndexer::nameMap.end())
		{
			cid = NameIndexer::count++;
			NameIndexer::nameMap[fndef] = cid;
		}
		else
		{
			cid = nameit->second;
		}
		stringstream ss;
		ss << 'f' << cid;
		return ss.str();
	}
}