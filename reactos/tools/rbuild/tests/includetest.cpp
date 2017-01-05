/*
 * Copyright (C) 2005 Casper S. Hornstrup
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#include "test.h"

using std::string;

void IncludeTest::Run()
{
	string projectFilename ( RBUILD_BASE "tests/data/include.xml" );
	Configuration configuration;
	Project project ( configuration, projectFilename );
	ARE_EQUAL(1, project.non_if_data.includes.size());
	Include& include1 = *project.non_if_data.includes[0];
	ARE_EQUAL("include1", include1.directory);

	ARE_EQUAL(2, project.modules.size());
	Module& module1 = *project.modules[0];
	Module& module2 = *project.modules[1];

	ARE_EQUAL(1, module1.non_if_data.includes.size());
	Include& include2 = *module1.non_if_data.includes[0];
	ARE_EQUAL("include2", include2.directory);

	ARE_EQUAL(1, module2.non_if_data.includes.size());
	Include& include3 = *module2.non_if_data.includes[0];
	ARE_EQUAL(FixSeparator("dir1/include3"), include3.directory);
}