// -*- c-basic-offset: 4 -*-
/*
 * stringtest.{cc,hh} -- regression test element for String
 * Tom Barbette
 *
 * Copyright (c) 2018 KTH Royal Institute of Technology
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, subject to the conditions
 * listed in the Click LICENSE file. These conditions include: you must
 * preserve this copyright notice, and you cannot mention the copyright
 * holders in advertising related to the Software without their permission.
 * The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
 * notice is a summary of the Click LICENSE file; the license in that file is
 * legally binding.
 */

#include <click/config.h>
#include "stringtest.hh"
#include <click/glue.hh>
#include <click/straccum.hh>
#include <click/error.hh>
CLICK_DECLS


StringTest::StringTest()
{
}

#define CHECK(x) if (!(x)) return errh->error("%s:%d: test `%s' failed", __FILE__, __LINE__, #x);

int
StringTest::initialize(ErrorHandler *errh)
{
    String empty = "";
    CHECK(empty == String::make_empty());

    //Split test
    CHECK(empty.split(';').size() == 0);
    CHECK(String("HELLO").split(';').size() == 1);
    CHECK(String("HELLO").split(';')[0] == "HELLO");
    CHECK(String("HELLO;YOU").split(';').size() == 2);
    CHECK(String("HELLO;YOU").split(';')[0] == "HELLO");
    CHECK(String("HELLO;YOU").split(';')[1] == "YOU");

    if (!errh->nerrors()) {
    	errh->message("All tests pass!");
		return 0;
    } else
    	return -1;
}

EXPORT_ELEMENT(StringTest)
ELEMENT_REQUIRES(userlevel)
CLICK_ENDDECLS
