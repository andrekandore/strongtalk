/* Copyright 1994, 1995 LongView Technologies L.L.C. $Revision: 1.7 $ */
/* Copyright (c) 2006, Sun Microsystems, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the 
following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following 
	  disclaimer in the documentation and/or other materials provided with the distribution.
    * Neither the name of Sun Microsystems nor the names of its contributors may be used to endorse or promote products derived 
	  from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT 
NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL 
THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE


*/

# include "incls/_precompiled.incl"
# include "incls/_vmSymbols.cpp.incl"

symbolOop vm_symbols[terminating_enum];

#define VMSYMBOL_INIT(name, string) \
  vm_symbols[VMSYMBOL_ENUM_NAME(name)] = oopFactory::new_symbol(string);

void vmSymbols::initialize() {
  VMSYMBOLS(VMSYMBOL_INIT)
}

void vmSymbols::switch_pointers(oop from, oop to) {
  for (int index = 0; index < terminating_enum; index++) {
    oop* p = (oop*) &vm_symbols[index];
    SWITCH_POINTERS_TEMPLATE(p)
  }
}

void vmSymbols::follow_contents() {
  for (int index = 0; index < terminating_enum; index++) {
    MarkSweep::follow_root((oop*) &vm_symbols[index]);
  }
}

void vmSymbols::relocate() {
  for (int index = 0; index < terminating_enum; index++) {
    oop* p = (oop*) &vm_symbols[index];
    RELOCATE_TEMPLATE(p);
  }
}

void vmSymbols::verify() {

}