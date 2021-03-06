// DESCRIPTION
//
//   Test to check whether the compiler supports namespace std, define HAVE_NAMESPACE_STD.
//   In sync with AC_CXX_NAMESPACE_STD (2008-04-12).
//
// COPYLEFT
//
//   Copyright (c) 2008 Todd Veldhuizen
//   Copyright (c) 2009 Theo Papadopoulo <Theodore.Papadopoulo@inria.fr>
//   Copyright (c) 2008 Luc Maisonobe <luc@spaceroots.org>
//
//   Copying and distribution of this file, with or without modification, are
//   permitted in any medium without royalty provided the copyright notice
//   and this notice are preserved.

#include <iostream>
std::istream& is = std::cin;

int main() { }
