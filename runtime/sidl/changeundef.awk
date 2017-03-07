BEGIN { PROTECTED=0 ; PREV="" ; VERSION="$Id$" }
/^\/\* Define to rpl_/ { PROTECTED=0 ; next }
/^#undef (re|m)alloc/ { PROTECTED=0 ; next }
/^#ifndef / { PROTECTED=1 ; PREV=$2; print $0 ; next }
/^#undef / { if ((PROTECTED==0) || ($2 != PREV)) { print "#ifndef", $2 ; print $0 ; print "#endif" } else { print $0 } ; PROTECTED=0 ; next }
{ print $0 ; PROTECTED=0 }
