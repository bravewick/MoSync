/* Copyright (C) 2009 Mobile Sorcery AB

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License, version 2, as published by
the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA.
*/

#include "common.h"
#include <ma.h>
#include <mastdlib.h>
#include <mastring.h>
#include <conprint.h>
#include <madmath.h>

class StringTestCase : public TestCase {

public:
	StringTestCase() : TestCase("String Test") {

	}

	void strtodTest() {

/** Macro magic to make sure that **/

#define TEST_DOUBLES(m)\
	m(1.0),\
	m(.0),\
	m(1e+5),\
	m(6.e10),\
	m(0.5e-6),\
	m(3.2E+4),\
	m(7.321E-3),\
	m(5.3876e4),\
	m(10000000)\

#define STRINGIZE(s) #s
#define COPY(s) s
#if 0	//unfinished
		const char* testStrings[] = {
				TEST_DOUBLES(STRINGIZE)
		};

		const double testDoubles[] = {
				TEST_DOUBLES(COPY)
		};

		for(size_t i = 0; i < sizeof(testStrings)/sizeof(testStrings[0]); i++) {

		}
#endif
	}

	void start() {
		printf("Automated string tests\n");
		strtodTest();
/*
 		printf("running math tests\n");
		doubleTest();
		trigTest();
		sqrtTest();
		suite->runNextCase();
*/
	}

};

void addStringTests(TestSuite* suite);
void addStringTests(TestSuite* suite) {
	suite->addTestCase(new StringTestCase());
}
