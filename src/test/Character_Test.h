/*
 * Character_Test.h
 *
 *  Created on: Jun 26, 2014
 *      Author: Dimas Melo Filho
 */

#ifndef CHARACTER_TEST_H_
#define CHARACTER_TEST_H_


#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/Test.h>
#include <iostream>
#include <cstdlib>
#include <memory>
#include "../expr/Character.h"
#include "ICompilable_Test.h"
using namespace std;

/**
 * Unit Test Fixture for the "Character" class.
 */
class CharacterTest : public CppUnit::TestFixture {
public:
	/**
	 * Returns the suite of tests for this fixture.
	 */
	static CppUnit::Test * suite() {
		CppUnit::TestSuite * s = new CppUnit::TestSuite("CharacterTest");
		s->addTest(new CppUnit::TestCaller<CharacterTest>("testCompile", &CharacterTest::testCompile));
		s->addTest(new CppUnit::TestCaller<CharacterTest>("testName", &CharacterTest::testName));
		return s;
	}

	/**
	 * Test preparations.
	 */
	void setUp() {
	}

	/**
	 * Post-test procedures.
	 */
	void tearDown() {
	}

	void testCompile() {
		// test with the character 'r';
		pgen::Character r('r');
		ICompilableTest::compileSource(r);
		CPPUNIT_ICOMPILABLE_ASSERT("e",255);
		CPPUNIT_ICOMPILABLE_ASSERT("",254);
		CPPUNIT_ICOMPILABLE_ASSERT("r",1);
		CPPUNIT_ICOMPILABLE_ASSERT("re",1);
		// test the character 'r' chained with an 'e', i.e. it looks for the text 're'
		pgen::Character e('e');
		ICompilableTest::ccompileSource(r,e.compile(),e.funcname());
		CPPUNIT_ICOMPILABLE_ASSERT("r", 255);
		CPPUNIT_ICOMPILABLE_ASSERT("e", 255);
		CPPUNIT_ICOMPILABLE_ASSERT("re", 2);
		CPPUNIT_ICOMPILABLE_ASSERT("ren", 2);
		CPPUNIT_ICOMPILABLE_ASSERT("", 254);
		ICompilableTest::clearFiles();
	}

	void testName() {
		pgen::Character c1(1000);
		pgen::Character c2(1234);
		pgen::Character c3(98765);
		CPPUNIT_ICOMPILABLE_ASSERTNAME(c1, "ch_1000");
		CPPUNIT_ICOMPILABLE_ASSERTNAME(c2, "ch_1234");
		CPPUNIT_ICOMPILABLE_ASSERTNAME(c3, "ch_98765");
	}
};




#endif /* CHARACTER_TEST_H_ */
