// Dear emacs, this is -*- c++ -*-
// $Id: TrigConfKeys.h 630856 2014-11-25 11:22:49Z gwatts $
#ifndef XAODTRIGGER_TRIGCONFKEYS_H
#define XAODTRIGGER_TRIGCONFKEYS_H

// Local include(s):
#include "xAODTrigger/versions/TrigConfKeys_v1.h"

namespace xAOD {
   /// Declare the current version of the trigger configuration keys type
   typedef TrigConfKeys_v1 TrigConfKeys;
}

// Declare the CLID for the class:
#include "xAODCore/CLASS_DEF.h"
CLASS_DEF( xAOD::TrigConfKeys, 33226429, 1 )

#endif // XAODTRIGGER_TRIGCONFKEYS_H
