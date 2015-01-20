/*
 * Code_Test.h
 *
 *  Created on: Jun 05, 2014
 *      Author: Dimas Melo Filho
 */

#ifndef CODE_TEST_H_
#define CODE_TEST_H_

// Includes for Testing
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/Test.h>
// STL
#include <iostream>
#include <sstream>
// Used Objects
#include "../expr/Code.h"
#include "../expr/Regex.h"
#include "ICompilable_Test.h"

using namespace std;
using namespace pagen;

/**
 * Unit Test Fixture for the "Code" class.
 */
class CodeTest : public CppUnit::TestFixture {
public:
	stringstream ss;
	Code code;
		
	/**
	 * Returns the suite of tests for this fixture.
	 */
	static CppUnit::Test * suite() {
		CppUnit::TestSuite * s = new CppUnit::TestSuite("CodeTest");
		s->addTest(new CppUnit::TestCaller<CodeTest>("testCompile", &CodeTest::testCompile));
		return s;
	}

	/**
	 * Test preparations.
	 */
	void setUp() {
		Regex regex("(a?b+c*|[d-f])+|[^a-z]+");
		code.add(&regex);
		ofstream o("___test___.c");
		o << code.code() << endl;
		o << "int main(int argc, char* argv[]) {" << endl;
		o << "\tchar* buffer = NULL;" << endl;
		o << "\tFILE *f;" << endl;
		o << "\tif (argc < 2) return -2;" << endl;
		o << "\tf = fopen(argv[1],\"r\");" << endl;
		o << "\tif (f != NULL && fseek(f, 0L, SEEK_END) == 0) {" << endl;
		o << "\t\tlong bufsize = ftell(f);" << endl;
		o << "\t\tif (bufsize == -1) return -2;" << endl;
		o << "\t\tbuffer = (char*)malloc(bufsize+1);" << endl;
		o << "\t\tif (buffer == NULL) return -2;" << endl;
		o << "\t\tif (fseek(f, 0L, SEEK_SET) != 0) return -2;" << endl;
		o << "\t\tif (fread(buffer, 1, bufsize, f) == 0) return -2;" << endl;
		o << "\t\tfclose(f);" << endl;
		o << "\t\treturn " << regex.funcname() << "(buffer);" << endl;
		o << "\t}" << endl;
		o << "\treturn -2;" << endl;
		o << "}" << endl;
		int res = system("gcc -o ___test___ ___test___.c") >> 8;	// compile using gcc
		CPPUNIT_ASSERT( res == 0 ); 								// assert a successfull compilation
		//system("rm -f ___test___.c"); 								// remove source
	}

	/**
	 * Post-test procedures.
	 */
	void tearDown() {
	}

	void testCompile() {		
		CPPUNIT_ICOMPILABLE_ASSERT("i",255);
		CPPUNIT_ICOMPILABLE_ASSERT("abc",3);
		CPPUNIT_ICOMPILABLE_ASSERT("bc",2);
		CPPUNIT_ICOMPILABLE_ASSERT("ac",255);
		CPPUNIT_ICOMPILABLE_ASSERT("ab",2);
		CPPUNIT_ICOMPILABLE_ASSERT("abba",3);
		CPPUNIT_ICOMPILABLE_ASSERT("abbab",5);
		CPPUNIT_ICOMPILABLE_ASSERT("abbabda",6);
		CPPUNIT_ICOMPILABLE_ASSERT("abbabdd",7);
		CPPUNIT_ICOMPILABLE_ASSERT("abbadd",3);
		CPPUNIT_ICOMPILABLE_ASSERT("abbab0",5);
		CPPUNIT_ICOMPILABLE_ASSERT("12345",5);
		CPPUNIT_ICOMPILABLE_ASSERT("12345a",5);		
		ICompilableTest::clearFiles();
	}

	void testName() {
		//CPPUNIT_ICOMPILABLE_ASSERTNAME(alt, "al_sq_ch_114_ch_101_sq_ch_100_ch_105");
	}
};




#endif /* CODE_TEST_H_ */
