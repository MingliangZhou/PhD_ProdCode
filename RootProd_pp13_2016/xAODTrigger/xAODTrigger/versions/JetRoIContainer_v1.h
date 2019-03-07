// Dear emacs, this is -*- c++ -*-
// $Id: JetRoIContainer_v1.h 630856 2014-11-25 11:22:49Z gwatts $
#ifndef XAODTRIGGER_VERSIONS_JETROICONTAINER_V1_H
#define XAODTRIGGER_VERSIONS_JETROICONTAINER_V1_H

// Core include(s):
#include "AthContainers/DataVector.h"

// Local include(s):
#include "xAODTrigger/versions/JetRoI_v1.h"

namespace xAOD {
   /// Declare the jet RoI container type
   typedef DataVector< xAOD::JetRoI_v1 > JetRoIContainer_v1;
}

#endif // XAODTRIGGER_VERSIONS_JETROICONTAINER_V1_H
