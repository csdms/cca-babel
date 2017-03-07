#
# File:          __init__.py
# Symbol:        sidl-v0.9.17
# Symbol Type:   package
# Babel Version: 2.0.0 (Revision: 7435  trunk)
# Release:       $Name:  $
# Revision:      @(#) $Id: $
# Description:   package initialization code
# 
# Copyright (c) 2000-2002, Lawrence Livermore National Security, LLC.
# Produced at the Lawrence Livermore National Laboratory.
# Written by the Components Team <components@llnl.gov>
# All rights reserved.
# 
# This file is part of Babel. For more information, see
# http://www.llnl.gov/CASC/components/. Please read the COPYRIGHT file
# for Our Notice and the LICENSE file for the GNU Lesser General Public
# License.
# 
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License (as published by
# the Free Software Foundation) version 2.1 dated February 1999.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the IMPLIED WARRANTY OF
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the terms and
# conditions of the GNU Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
# 
# WARNING: Automatically generated; changes will be lost
# 
#


"""The <code>sidl</code> package contains the fundamental type and interface
definitions for the <code>sidl</code> interface definition language.  It
defines common run-time libraries and common base classes and interfaces.
Every interface implicitly inherits from <code>sidl.BaseInterface</code>
and every class implicitly inherits from <code>sidl.BaseClass</code>.
"""

__all__ = [
   "BaseClass",
   "BaseException",
   "BaseInterface",
   "CastException",
   "ClassInfo",
   "ClassInfoI",
   "ClauseType",
   "ContractClass",
   "DFinder",
   "DLL",
   "EnfPolicy",
   "EnfTraceLevel",
   "EnforceFreq",
   "Finder",
   "InvViolation",
   "LangSpecificException",
   "Loader",
   "MemAllocException",
   "NotImplementedException",
   "PostViolation",
   "PreViolation",
   "Resolve",
   "RuntimeException",
   "SIDLException",
   "Scope",
   "io",
   "rmi" ]

try:
  from pkgutil import extend_path
  __path__ = extend_path(__path__, __name__)
except: # ignore all exceptions
  pass
