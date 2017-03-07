// 
// File:        helloclient.cc
// Copyright:   (c) 2001 Lawrence Livermore National Security, LLC
// Revision:    @(#) $Revision$
// Date:        $Date$
// Description: Simple Hello World C++ client
// 
// 

#include <iostream>
#include <stdio.h>
using namespace std;
#include "Hello_World.hxx"

#ifdef SIDL_USE_UCXX
using namespace ucxx;
#endif /* UCXX namespace */
using Hello::World;

int 
main (int argc, char** argv) 
{
  Hello::World h = Hello::World::_create ();
  std::string msg = h.getMsg ();
  std::cout << msg << endl;
//  msg = h.extractMsg(h);
//  std::cout << msg << endl;

}
