// Aqsis
// Copyright (C) 2001, Paul C. Gregory and the other authors and contributors
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
// * Neither the name of the software's owners nor the names of its
//   contributors may be used to endorse or promote products derived from this
//   software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// (This is the New BSD license)

/** \file
 *
 * \brief Unit tests for primvar token class.
 *
 * \author Chris Foster [ chris42f (at) g mail (dot) com ]
 */

#include <aqsis/riutil/primvartoken.h>

#define BOOST_TEST_DYN_LINK

#include <boost/test/auto_unit_test.hpp>

#include <aqsis/util/exception.h>

using namespace Aqsis;

BOOST_AUTO_TEST_SUITE(primvartoken_tests)

BOOST_AUTO_TEST_CASE(CqPrimvarToken_parse_test)
{
	{
		// Check basic behaviour
		CqPrimvarToken tok("vertex float[2] st");
		BOOST_CHECK_EQUAL(tok.Class(), class_vertex);
		BOOST_CHECK_EQUAL(tok.type(), type_float);
		BOOST_CHECK_EQUAL(tok.count(), 2);
		BOOST_CHECK_EQUAL(tok.name(), "st");
	}

	{
		// Check whitespace handling.
		CqPrimvarToken tok("\n  vertex \tfloat [ 2 ] st    ");
		BOOST_CHECK_EQUAL(tok.Class(), class_vertex);
		BOOST_CHECK_EQUAL(tok.type(), type_float);
		BOOST_CHECK_EQUAL(tok.count(), 2);
		BOOST_CHECK_EQUAL(tok.name(), "st");
	}

	{
		// Check capitalization handling
		CqPrimvarToken tok("VERTEX veCtor P");
		BOOST_CHECK_EQUAL(tok.Class(), class_vertex);
		BOOST_CHECK_EQUAL(tok.type(), type_vector);
		BOOST_CHECK_EQUAL(tok.count(), 1);
		BOOST_CHECK_EQUAL(tok.name(), "P");
	}

	{
		// Check a special case - integer types can be specified either with
		// "int" or with "integer"
		CqPrimvarToken tok("uniform int i");
		BOOST_CHECK_EQUAL(tok.type(), type_integer);
	}
}

BOOST_AUTO_TEST_CASE(CqPrimvarToken_parse_defaults_test)
{
	{
		CqPrimvarToken tok("matrix some_mat");
		BOOST_CHECK_EQUAL(tok.Class(), class_uniform);
		BOOST_CHECK_EQUAL(tok.type(), type_matrix);
		BOOST_CHECK_EQUAL(tok.count(), 1);
		BOOST_CHECK_EQUAL(tok.name(), "some_mat");
	}

	{
		CqPrimvarToken tok("matrix", "some_mat");
		BOOST_CHECK_EQUAL(tok.Class(), class_uniform);
		BOOST_CHECK_EQUAL(tok.type(), type_matrix);
		BOOST_CHECK_EQUAL(tok.count(), 1);
		BOOST_CHECK_EQUAL(tok.name(), "some_mat");
	}
}

// tests for parsing invalid tokens.
BOOST_AUTO_TEST_CASE(CqPrimvarToken_invalid_parse_test)
{
	// invalid/incomplete token sequences
	BOOST_CHECK_THROW(CqPrimvarToken("] u"), XqParseError);
	BOOST_CHECK_THROW(CqPrimvarToken("[ u"), XqParseError);
	BOOST_CHECK_THROW(CqPrimvarToken("[ 2"), XqParseError);
	BOOST_CHECK_THROW(CqPrimvarToken("["), XqParseError);
	BOOST_CHECK_THROW(CqPrimvarToken("float varying u"), XqParseError);
	BOOST_CHECK_THROW(CqPrimvarToken("varying u"), XqParseError);
	BOOST_CHECK_THROW(CqPrimvarToken("[2] u"), XqParseError);
	BOOST_CHECK_THROW(CqPrimvarToken("[2] float st"), XqParseError);
	BOOST_CHECK_THROW(CqPrimvarToken("P Cs"), XqParseError);
	BOOST_CHECK_THROW(CqPrimvarToken("P", "Cs"), XqParseError);
}

BOOST_AUTO_TEST_SUITE_END()
